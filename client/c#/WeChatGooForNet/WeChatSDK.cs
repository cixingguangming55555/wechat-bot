using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net.WebSockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Newtonsoft.Json;
//using Fleck;
using ThreadState = System.Threading.ThreadState;
using Newtonsoft.Json.Linq;
using System.Data;
using System.Windows.Forms;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices.WindowsRuntime;
//using System.Runtime.InteropServices;

namespace Ebliskey.WeChatGooForNet
{
    public class WeChatSDK
    {
        class Nested
        {
            internal static readonly WeChatSDK instance = new WeChatSDK();
        }
        /// <summary>
        /// WeChatSDK入口点
        /// </summary>
        public static WeChatSDK Instance { 
            get {

                return Nested.instance; 
            } 
        }

        //version2.8.0.121-2.6.4.63.dll /version2.8.0.121-2.5.4.61.dll
        //private static string dllName = "version2.8.0.121-2.5.4.61.dll";
        //private static string dllName = "version2.8.0.121-2.6.4.63.dll";
        private static string dllName = "version2.8.0.121-2.8.5.65.dll";
        private static string dllPath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, dllName);
        private static string url = "ws://127.0.0.1:5555/";
        private ClientWebSocket WeChatHelper = new ClientWebSocket();
        private CancellationToken _cancellation = new CancellationToken();
        private const int USER_LIST = 5000;
        private const int TEXT_MESSAGE = 555;
        private const int IMAGE_MESSAGE = 500;
        private const int AT_MESSAGE = 550;
        private const int PERSONAL_INFO = 6500;
        private const int USER_INFO = 6550;
        private const int CHATROOM_USER_LIST = 5010;
        private const int CHATROOM_USER_NAME = 5020;
        private const int DEBUG_MESSAGE = 6000;
        private Thread Receiving = null;
        private static Process WeChatProcess = null;


        //private static DataTable tab_User = new DataTable();

        private static string baseRecMessage = null;
        private static Queue<string> RecMessage = new Queue<string>();
        //private static Queue<string> ChatRoom = new Queue<string>();

        private static string USERLIST = null;
        private static string USERINFO = null;
        private static string DEBUGINFO = "on";
        private static string CHATROOMINFO = null;
        private static Dictionary<string, string> User = new Dictionary<string, string>();
        private static Dictionary<string, string> Chatroom = new Dictionary<string, string>();
        private static List<Chatroom> ChatroomUser = new List<Chatroom>();
        private static Dictionary<string, string> UpDataLog = new Dictionary<string, string>();
        private static List<User> UserDetailedInfo = new List<User>();

        //适当的调节可节省CPU的开销...
        private const int wait_for_open_wechat = 1000;
        private const int wait_for_inject_to_wechat_prcoess = 1000;
        private const int wait_for_websocker_server_response = 1000;
        private const int wait_for_websocker_server_init = 100;
        private const int wait_for_request_contactlist = 1000;
        private const int Wait_for_Receive_Messages = 100;
        private const int wait_for_request_user_info = 1000;

        //暂时设定为最近5分钟吧
        private const int last_update_for_contact = 1000 * 60 * 5;
        private static int Wait_for_release_cpu = 100;

        /// <summary>
        /// 微信进程状态
        /// </summary>
        public enum WeChatStatus {
            opening,
            closed,
            waiting_for_login,
            background_runing,
            unkown,
        }

        public int ReleaseCPU
        {
            get{
                return Wait_for_release_cpu;
            }
            set{
                Wait_for_release_cpu = value;
            }
        }

        /// <summary>
        /// 启动并完成初始化
        /// </summary>
        private WeChatSDK()
        {
            if (WeChatProcess == null) OpenWeChat();
            while (true) {
                if (GetWeChatStatus() == WeChatStatus.opening) break;
                Trace.WriteLine(String.Format("微信状态:{0}...准备注入模块...", GetWeChatStatus().ToString()));
                Thread.Sleep(wait_for_open_wechat);
            }
            try {
                this.InjectDll(WeChatProcess);
                do {
                    Thread.Sleep(wait_for_inject_to_wechat_prcoess);
                    Trace.WriteLine(String.Format("[{1}]注入状态:{0},等待模块启动...", IsInjectDll(), DateTime.Now.ToString()));
                } while (!IsInjectDll());

                this.ConnectionToWebSocketServer(WeChatHelper).Wait();
                Thread.Sleep(wait_for_websocker_server_init);
                this.Start();



                //tab_User.TableName = "User_Info_table";
            }
            catch (Exception e)
            {
                throw e;
            }

        }


        /// <summary>
        /// 连接到WebSocket服务器
        /// </summary>
        /// <param name="_cws">提供ClientWebSocket连接类型</param>
        private async Task ConnectionToWebSocketServer(ClientWebSocket _cws=null)
        {
            if (_cws is null) _cws = WeChatHelper;
            try
            {
                Trace.WriteLine("Websocket连接状态:{0},连接中...", _cws.State.ToString());

                await _cws.ConnectAsync(new Uri(url), _cancellation);

                while (_cws.State != WebSocketState.Open) {
                    Trace.WriteLine("Websocket连接状态:{0},连接中...", _cws.State.ToString());
                    Thread.Sleep(wait_for_websocker_server_response);
                }
                Trace.WriteLine(String.Format("Websocker连接状态:{0},连接WebSocket服务器成功！", _cws.State).ToString());
            } catch (Exception e)
            {
                throw e;
            }
        }

        /// <summary>
        /// 注入模块名称
        /// </summary>
        public string InjectDllName
        {
            get {
                return dllName;
            }
            set
            {

                dllName = value;
            }
        }
        /// <summary>
        /// Websocket服务地址
        /// </summary>
        public string WebSocketURL {
            get {
                return url;
            }
            set
            {
                url = value;
            }

        }


        public User UserInfo
        {
            get
            {
                return  this.FormatUserInfo(this.GetUserInfo());
            }
        }

        /// <summary>
        /// 获取微信状态
        /// </summary>
        /// <returns></returns>
        public WeChatStatus GetWeChatStatus() {
            Process _wx = GetWeChatProcess();
            if (_wx == null) return WeChatStatus.closed;
            if ((int)_wx.MainWindowHandle == 0) return WeChatStatus.background_runing;
            if ((int)_wx.MainWindowHandle > 0 && _wx.MainWindowTitle.ToString().ToUpper().Trim() == "微信") return WeChatStatus.opening;
            if ((int)_wx.MainWindowHandle > 0 && _wx.MainWindowTitle.ToString().ToUpper().Trim() == "登录") return WeChatStatus.waiting_for_login;
            Trace.WriteLine(String.Format("主线程Handle:{0},主窗口Handle:{1},主窗口标题:{2}.", _wx.Handle, _wx.MainWindowHandle, _wx.MainWindowTitle));
            return WeChatStatus.unkown;
        }


        /// <summary>
        /// 注入校验
        /// </summary>
        /// <returns></returns>
        public bool IsInjectDll() {
            WeChatProcess = GetWeChatProcess();
            if (WeChatProcess == null) throw new Exception(String.Format("[{0}]微信未运行",DateTime.Now.ToString()));
            if (WeChatProcess.Modules.OfType<ProcessModule>().Any(o => o.ModuleName.Contains(dllName)))
                return true;
            return false;
        }

        /// <summary>
        /// 获取注入的DLL的基址;
        /// </summary>
        /// <returns></returns>
        public IntPtr GetInjectBaseAddress() {
            if (WeChatProcess == null) return new IntPtr(0);
            foreach (ProcessModule _pm in WeChatProcess.Modules) {
                if (_pm.ModuleName == dllName) return _pm.BaseAddress;
            }
            return new IntPtr(0);
        }

        /// <summary>
        /// 从进程中查找指定模块
        /// </summary>
        /// <param name="_ps"></param>
        /// <param name="_moduleName"></param>
        /// <returns></returns>
        private ProcessModule getModuleForProcess(Process _ps = null , String _moduleName="WeChatWin.dll") {

            if (_ps == null) _ps = GetWeChatProcess();
            var _module = _ps.Modules.OfType<ProcessModule>().Where(o => o.ModuleName.ToLower() == _moduleName.ToLower()) ;
            return (ProcessModule)_module.FirstOrDefault();


        }

        /// <summary>
        /// 注入Dll到微信进程
        /// </summary>
        public void InjectDll(Process _wxProcess) {
            WeChatProcess = _wxProcess;
            if (WeChatProcess == null) throw new Exception(String.Format("[{0}]微信未运行", DateTime.Now.ToString()));
            if (!File.Exists(dllPath)) throw new Exception(String.Format("[{0}]请确认程序目录下是否存在[{1}]文件！",DateTime.Now.ToString(),dllName));
            if (IsInjectDll()) {
                Trace.WriteLine(String.Format("[{0}]模块已经存在,不能再注入;要重新注入请重启微信.",DateTime.Now.ToString()));
                return;
            }

            int DllPathSize = dllPath.Length * 2 + 1;
            int MEM_COMMIT = 0x00001000;
            int PAGE_READWRITE = 0x04;
            int DllAddress = Win32API.VirtualAllocEx((int)WeChatProcess.Handle, 0, DllPathSize, MEM_COMMIT, PAGE_READWRITE);
            if (DllAddress == 0) throw new Exception(String.Format("申请dll内存失败。"));


            //把DLL文件路径字符串写入到申请的内存中（WriteProcessMemory）
            if (Win32API.WriteProcessMemory((int)WeChatProcess.Handle, DllAddress, dllPath, DllPathSize, 0) == false) throw new Exception("内存写入失败。");

            //从Kernel32.dll中获取LoadLibraryA的函数地址（GetModuleHandle、GetProcAddress）
            int module = Win32API.GetModuleHandleA("Kernel32.dll");
            int LoadLibraryAddress = Win32API.GetProcAddress(module, "LoadLibraryA");
            if (LoadLibraryAddress == 0) throw new Exception(String.Format("查找LoadLibraryA地址失败。"));

            //在微信中启动内存中指定了文件名路径的DLL（CreateRemoteThread）。
            var _injectflag = Win32API.CreateRemoteThread((int)WeChatProcess.Handle, 0, 0, LoadLibraryAddress, DllAddress, 0, 0);
            if ( _injectflag == 0) throw new Exception(String.Format("执行远程线程失败。"));

            Trace.WriteLine(String.Format("模块已经成功注入."));
        }


        /// <summary>
        /// 卸载注入的Dll,还存在问题，会导致主线程关闭；
        /// </summary>
        public void UnInjectDll() {
            IntPtr DllmodAddress = new IntPtr(0);

            if (WeChatProcess == null) throw new Exception(String.Format("{0}微信未运行.",DateTime.Now.ToString()));
            if (!IsInjectDll()) return;

            foreach (ProcessModule _pm in WeChatProcess.Modules) {
                if (_pm.ModuleName == dllName) {
                    DllmodAddress = _pm.BaseAddress;
                }
            }

            int DllPathSize = dllPath.Length * 2 + 1;
            //int MEM_COMMIT = 0x00001000;
            int MEM_COMMIT = 0x00008000;
            //int PAGE_READWRITE = 0x04;
            bool _flg = Win32API.VirtualFreeEx((int)WeChatProcess.Handle, (int)DllmodAddress, DllPathSize, MEM_COMMIT);
            if (!_flg) throw new Exception(String.Format("清理内存空间失败"));

            //VirtualFreeEx(hProcess, lpBuf, dwSize, MEM_DECOMMIT);

            int module = Win32API.GetModuleHandleA("Kernel32.dll");
            // LoadLibraryAddress = Win32API.GetProcAddress(module, "FreeLibrary");
            int LoadLibraryAddress = Win32API.GetProcAddress(module, "FreeLibraryAndExitThread");
            if (LoadLibraryAddress == 0) throw new Exception(String.Format("查找LoadLibraryA地址失败。"));

            //在微信中启动内存中指定了文件名路径的DLL（CreateRemoteThread）。
            //if (Win32API.CreateRemoteThread((int)GetWeChatProcess().Handle, 0, 0, LoadLibraryAddress, (int)DllmodAddress, 0, 0) == 0) throw new Exception("执行远程线程失败。");
            int _handle = Win32API.CreateRemoteThread((int)GetWeChatProcess().Handle, 0, 0, LoadLibraryAddress, (int)DllmodAddress, 0, 0);
            //Win32API.WaitForSingleObject(new IntPtr(_handle), 0);
            Trace.WriteLine(String.Format("卸载成功..................."));
        }

        /// <summary>
        /// 获取微信进程实例
        /// </summary>
        /// <param name="_process">默认WeChat</param>
        /// <returns></returns>
        public Process GetWeChatProcess(string _process = "WeChat")
        {
            //if (WeChatProcess != null) return WeChatProcess;

            Process[] processes = Process.GetProcesses();
            foreach (Process process in processes)
            {
                if (process.ProcessName.ToLower() == _process.ToLower())
                {
                    WeChatProcess = process;
                    //foreach (ProcessModule processModule in WxProcess.Modules)
                    //{
                    //    if (processModule.ModuleName == dllName) return;
                    //}
                    Trace.WriteLine(String.Format("[{0}]找到{1}进程，进程号为:{2}",DateTime.Now.ToString() , _process , WeChatProcess.Id.ToString()));
                    break;
                }
            }
            return WeChatProcess;
        }

        /// <summary>
        /// 返回微信进程号
        /// </summary>
        /// <returns>失败返回-1;</returns>
        public int GetWeChatProcessId() {
            if (WeChatProcess == null) return -1;
            return WeChatProcess.Id;
            //return WeChatProcessId;
        }

        /// <summary>
        /// 获取进程Module列表
        /// </summary>
        /// <returns>失败返回null</returns>
        public List<string> GetModelList() {
            if (WeChatProcess == null) return null;
            List<string> _ModelList = new List<string>();
            foreach (ProcessModule _pm in WeChatProcess.Modules) {
                _ModelList.Add(_pm.ModuleName);
            }

            return _ModelList;
        }

        /// <summary>
        /// 获取进程中模块名称及基址
        /// </summary>
        /// <param name="_wx">要查找的进程</param>
        /// <returns></returns>
        public List<string> GetAllModulesBaseAddress(Process _wx) {
            if (_wx == null) return null;
            List<string> _modules = new List<string>();
            foreach (ProcessModule _pm in _wx.Modules) {
                _modules.Add(String.Format("模块名称:{0},模块基址:0x{1}", _pm.ModuleName, _pm.BaseAddress.ToString("x8").ToUpper()));
                Trace.WriteLine(String.Format("模块名称:{0},模块基址:0x{1}", _pm.ModuleName, _pm.BaseAddress.ToString("x8").ToUpper()));
            }
            return _modules;
        }

        /// <summary>
        /// 查找进程中模块的基址
        /// </summary>
        /// <param name="_wx">进程实例</param>
        /// <param name="_module">模块名称</param>
        /// <returns>不存在返回0</returns>
        public IntPtr FindModuleBaseAddress(Process _wx, string _module = "") {
            IntPtr _baseAddress = new IntPtr(0);
            if (_wx == null) return _baseAddress;
            if (_module == "") {
                _baseAddress = _wx.MainModule.BaseAddress;
            }
            else
            {
                foreach (ProcessModule _pm in _wx.Modules)
                {
                    if (_pm.ModuleName.ToLower() == _module.ToLower()) _baseAddress = _pm.BaseAddress;
                }
            }
            return _baseAddress;
        }


        /// <summary>
        /// 打开微信
        /// </summary>
        /// <returns>成功返回进程实例,失败返回null;</returns>
        public Process OpenWeChat() {
            //在注册表中查找微信
            //计算机\HKEY_CURRENT_USER\Software\Tencent\WeChat
            //InstallPath
            string WxPath = "";
            try
            {
                RegistryKey registryKey = Registry.CurrentUser;
                RegistryKey software = registryKey.OpenSubKey("Software\\Tencent\\WeChat", true);
                object InstallPath = software.GetValue("InstallPath");
                WxPath = InstallPath.ToString() + "\\WeChat.exe";

                //NeedUpdateType 设置低于100，禁止自动升级
                software.SetValue("NeedUpdateType", 80);

                registryKey.Close();
            }
            catch (Exception ex)
            {
                WxPath = "";
                Trace.WriteLine(String.Format("打开微信异常:{0}",ex.Message));
            }

            if (!string.IsNullOrEmpty(WxPath))
            {
                WeChatProcess = Process.Start(WxPath);
                return WeChatProcess;
            }
            return null;
        }

        /// <summary>
        /// 获取时间戳
        /// </summary>
        /// <returns></returns>
        private string GetTimeStamp()
        {
            TimeSpan ts = DateTime.UtcNow - new DateTime(1970, 1, 1, 0, 0, 0, 0);
            return Convert.ToInt64(ts.TotalMilliseconds).ToString();
        }
        /// <summary>
        /// 生成通讯Id
        /// </summary>
        /// <returns></returns>
        private string getId()
        {
            //return GetTimeStamp() + new Random().Next().ToString();
            return GetTimeStamp();
        }


        /// <summary>
        /// 启动监听模式
        /// </summary>
        public void Start(ClientWebSocket _cws=null) {
            if (_cws == null) _cws = WeChatHelper;
            //if (_cws.State == WebSocketState.Open) return;
            //if (_cws.State == WebSocketState.CloseSent || _cws.State == WebSocketState.Closed || _cws.State == WebSocketState.None || _cws.State == WebSocketState.Aborted) {
            //    //this.ConnectionToWebSocketServer(_cws = new ClientWebSocket()).Wait();
            //    _cws = new ClientWebSocket();
            //    _cws.ConnectAsync(new Uri(url),CancellationToken.None).Wait();
            //    Trace.WriteLine(String.Format("[{0}]重新连接到WebSocket服务器...",DateTime.Now.ToString()));
            //    Thread.Sleep(wait_for_websocker_server_init);
            //}

            Trace.WriteLine(String.Format("Websocket状态:{0},启动监听模式...",_cws.State.ToString()));


            Receiving = new Thread(() =>
            {
                StartReceiving(_cws);
            });
            Receiving.Name = "listening";
            Receiving.IsBackground = true;
            Receiving.Start();
            //ThreadPool.QueueUserWorkItem(_tp =>
            //{
            //    StartReceiving(WeChatHelper);
            //});

        }

        /// <summary>
        /// 停止监听
        /// </summary>
        public void Stop()
        {
            Receiving.Abort();
        }


        public void CloseWebSocket(ClientWebSocket client = null) {
            if (client == null) client = WeChatHelper;
            if (client.State == WebSocketState.CloseSent || client.State == WebSocketState.Closed) return;
            client.CloseOutputAsync(WebSocketCloseStatus.NormalClosure,String.Format("[{0}]主动关闭连接...",DateTime.Now.ToString()),CancellationToken.None).Wait();
            Trace.WriteLine(String.Format ("[{0}]连接已关闭，状态:{1}.",DateTime.Now.ToString(),client.State.ToString()));
        }

        /// <summary>
        /// 消息回传
        /// </summary>
        /// <param name="client"></param>
        async void StartReceiving(ClientWebSocket client)
        {
            if (client is null) client = WeChatHelper;
            string _result = "";
            while (true)
            {
                Trace.WriteLine(String.Format("在线程[{0}]收到消息.", Thread.CurrentThread.ManagedThreadId.ToString()));
                var array = new byte[4096];
                var result = await client.ReceiveAsync(new ArraySegment<byte>(array), CancellationToken.None);

                if (result.MessageType == WebSocketMessageType.Text)
                {

                    Trace.WriteLine(String.Format("[{0}]Client Status:{1}.",DateTime.Now.ToString(),client.State.ToString()));
                    Trace.WriteLine(String.Format("[{0}]收到:{1}.",DateTime.Now.ToString(),_result));
                    string msg = Encoding.UTF8.GetString(array, 0, result.Count);
                    if (result.EndOfMessage)
                    {
                        _result += msg;
                        baseRecMessage = _result;
                        var _json = JObject.Parse(_result);
                        switch (_json["type"].ToString().ToLower())
                        {
                            case "1"://文本消息
                            case "3"://图片消息
                                RecMessage.Enqueue(_result);
                                break;
                            case "5001"://获取联系人及群消息类型，一个群也相当于一个联系人
                                if (UpDataLog.ContainsKey("USERLIST"))
                                {
                                    UpDataLog["USERLIST"] = GetTimeStamp();
                                }
                                else
                                {
                                    UpDataLog.Add("USERLIST", GetTimeStamp());
                                }
                                USERLIST = _result;
                                Trace.WriteLine(String.Format("获取通讯录列表完成,[{0}]", _result));
                                new Thread(new ThreadStart(RefreshContactList));
                                break;
                            case "5005"://WebSocket心跳消息
                                RecMessage.Enqueue(_result);
                                Trace.WriteLine(String.Format("[{0}]WebSocket connection is onlive.",DateTime.Now.ToString()));
                                break;
                            case "5010"://获取群成员返回消息类型
                            case "5020":
                                CHATROOMINFO = _result;
                                ThreadPool.QueueUserWorkItem(p=>{
                                    RefreshChatRoomUser(CHATROOMINFO);
                                });
                                break;
                            case "6000"://调试信息开关
                                DEBUGINFO = _result;
                                break;
                            case "6500"://获取个人信息
                            case "6550"://获取个人信息
                                USERINFO = _result;
                                ThreadPool.QueueUserWorkItem(p => {
                                    FormatUserInfo(USERINFO);
                                });
                                break;
                            default:
                                RecMessage.Enqueue(_result);
                                break;
                        };
                        _result = null;
                    }
                    else
                    {
                        _result += msg;
                    }
                }
                Thread.Sleep(Wait_for_Receive_Messages);
            }
        }

        /// <summary>
        /// 发送数据到websokect服务器
        /// </summary>
        /// <param name="_msg">String消息内容</param>
        /// <returns></returns>
        private void Send(ClientWebSocket _cws, string _msg = "") {
            var _msgArr = new ArraySegment<byte>(Encoding.UTF8.GetBytes(_msg));
            _cws.SendAsync(_msgArr, WebSocketMessageType.Text, true, CancellationToken.None).Wait();
        }


        /// <summary>
        /// 请求通讯录列表
        /// </summary>
        private void RequerContactList()
        {
            Dictionary<string, object> _dic = new Dictionary<string, object>();
            _dic.Add("id", getId());
            _dic.Add("type", USER_LIST);
            _dic.Add("content", "user list");
            _dic.Add("wxid", "ROOT");
            //Trace.WriteLine(JsonConvert.SerializeObject(_dic));
            Send(WeChatHelper, JsonConvert.SerializeObject(_dic));
            Trace.WriteLine(String.Format("获取通讯录列表,请求消息内容:[{0}]", JsonConvert.SerializeObject(_dic)));
        }

        /// <summary>
        /// 提取消息队列
        /// </summary>
        public string GetMessage
        {
            get
            {
                if (RecMessage.Count <= 0) return null;
                return RecMessage.Dequeue();
            }
        }
        /// <summary>
        /// 消息队列总数
        /// </summary>
        public int MessageTotal
        {
            get
            {
                return RecMessage.Count;
            }
        }
        /// <summary>
        /// 调试信息设置
        /// </summary>
        public Hook_Degbug_flg DebugInfo
        {
            get
            {
                if (DEBUGINFO is null) return Hook_Degbug_flg.on;
                if (DEBUGINFO.ToLower().Contains("off")) return Hook_Degbug_flg.off;
                return Hook_Degbug_flg.on;
            }
            set
            {
                SetDebugInfo(value);
            }
        }
        /// <summary>
        /// 根据ID查找昵称
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        public string FindIdForName(string name)
        {
            if (USERINFO is null) RefreshContactList();
            var _result = this.ContactList.FindAll(o => o.UserName == name);
            List<String> _str = new List<string>();
            foreach (var _i in _result)
            {
                _str.Add(_i.Id.ToString());
            }
            return String.Join(",", _str);
        }
        /// <summary>
        /// 根据昵称查找ID
        /// </summary>
        /// <param name="_id"></param>
        /// <returns></returns>
        public string FindNameForId(string _id)
        {
            if (USERINFO is null) RefreshContactList();
            var _result = this.ContactList.FindAll(o => o.Id == _id);
            List<String> _str = new List<string>();
            foreach (var _i in _result)
            {
                _str.Add(_i.Id.ToString());
            }
            return String.Join(",", _str);
        }

        /// <summary>
        /// 返回群中联系人的昵称
        /// </summary>
        /// <param name="wxid">联系人wechatID</param>
        /// <param name="chatroomId">群Id</param>
        /// <returns></returns>
        public string FindNickNameAtChatroomForId(string wxid, string chatroomId)
        {
            string[] _wxid;
            _wxid = wxid.Split(Char.Parse(","));

            foreach (var i in _wxid)
            {
                if (IsAtChatroomForId(i)) return ChatroomUser.Find(o => o.WeChatId == i && o.ChatroomId == chatroomId).NickName;
            }
            return null;
        }

        public User TestInfo
        {
            get
            {
                User _user = new User();
                _user.NickName = "testNickname";
                _user.Account = "testWxid";
                return _user;
            }
        }

        public bool IsAtChatroomForId(string wxid)
        {
            if (ChatroomUser.OfType<Chatroom>().Any(o => o.WeChatId.Contains(wxid))) return true;
            return false;
        }


        private void RefreshChatRoomUser(String _chatroomInfo) {

            JObject _json = JObject.Parse(_chatroomInfo);
            JArray _jArray = JArray.Parse(_json["content"].ToString());
            foreach (var i in _jArray)
            {
                // {"nickname":"诺阳","roomid":"24053875279@chatroom","wxid":"huzixiaosi"},
                Chatroom _chatroom = new Chatroom();
                _chatroom.ChatroomId = i["roomid"].ToString();
                _chatroom.NickName = i["nickname"].ToString();
                _chatroom.WeChatId = i["wxid"].ToString();

                if (!ChatroomUser.Contains(_chatroom)) ChatroomUser.Add(_chatroom);

            }

        }

        private User FormatUserInfo(string _userinfo)
        {

            JObject _json = JObject.Parse(_userinfo);
            JObject _json_user = JObject.Parse(_json["content"].ToString());
            User _user = new User();
            _user.Account = _json_user["wxid"].ToString();
            _user.NickName = _json_user["nick"].ToString();
            _user.City = _json_user["city"].ToString();
            _user.BigHeader = _json_user["headimg959"].ToString();
            _user.EMail = _json_user["mail"].ToString();
            _user.Nation = _json_user["country"].ToString();
            _user.PhoneNumber = _json_user["mobile"].ToString();
            _user.Province = _json_user["province"].ToString();

            if (!(UserDetailedInfo.Contains(_user))) UserDetailedInfo.Add(_user);
            return _user;
            
        }


        /// <summary>
        /// 格式化通讯列表
        /// </summary>
        private void RefreshContactList()
        {
            if (UpDataLog.ContainsKey("USERLIST"))
                if ((Decimal.Parse(GetTimeStamp()) - Decimal.Parse(UpDataLog["USERLIST"])) < last_update_for_contact) return;

            new Thread(new ThreadStart(RequerContactList)).Start();

            //using (Task _task = new Task(() =>
            //{
            //    RequerContactList();
            //}))
            Thread.Sleep(wait_for_request_contactlist);


            JObject _json = JObject.Parse(USERLIST);
            JArray _jsonArr = JArray.Parse(_json["content"].ToString());
            foreach (var _ob in _jsonArr)
            {
                JObject _t = (JObject)_ob;
                if (_t["wxid"].ToString().Contains("@chatroom"))
                {
                    if (!Chatroom.ContainsKey(_t["wxid"].ToString()))
                        Chatroom.Add(_t["wxid"].ToString(), _t["name"].ToString());
                }
                else
                {
                    if (!User.ContainsKey(_t["wxid"].ToString()))
                        User.Add(_t["wxid"].ToString(), _t["name"].ToString());
                }
            }
            Trace.WriteLine(String.Format("格式化通讯录列表完成"));
        }

        /// <summary>
        /// 联系人列表(包括群)
        /// </summary>
        public List<Contact> ContactList {
            get
            {
                if (USERLIST is null) this.RefreshContactList();

                List<Contact> _list = new List<Contact>();
                JObject _json = JObject.Parse(USERLIST);
                JArray _jsonArr = JArray.Parse(_json["content"].ToString());
                foreach (var _ob in _jsonArr)
                {
                    JObject _t = (JObject)_ob;
                    Contact _contact = new Contact();
                    _contact.Id = _t["wxid"].ToString();
                    _contact.UserName = _t["name"].ToString();
                    _list.Add(_contact);
                }

                return _list;
            }
        }


        /// <summary>
        /// 获取通讯录
        /// </summary>
        public Dictionary<string, string> GetUserList
        {
            get
            {
                this.RefreshContactList();
                return User;
            }

        }
        /// <summary>
        /// 获取群聊列表
        /// </summary>
        public Dictionary<String, string> GetChatRoom
        {
            get
            {
                this.RefreshContactList();
                return Chatroom;
            }
        }
        /// <summary>
        /// 获取最后一条原始格式的消息
        /// </summary>
        public string GetBaseMessage{
            get
            {
                return baseRecMessage;
            }
        }
        

        /// <summary>
        /// 发送文字消息
        /// </summary>
        /// <param name="wxid">string,接收方的wxid</param>
        /// <param name="msg">string,消息内容</param>
        public void SendTextMessage(string wxid="null",string msg="null") {
            Dictionary<string, object> _dic = new Dictionary<string, object>();
            _dic.Add("id", getId());
            _dic.Add("type",TEXT_MESSAGE);
            _dic.Add("content",msg);
            _dic.Add("wxid", wxid);
            Trace.WriteLine(JsonConvert.SerializeObject(_dic));
            Send(WeChatHelper, JsonConvert.SerializeObject(_dic));
        }

        /// <summary>
        /// 发送AT消息
        /// </summary>
        /// <param name="_wxid">微信号[这个版本有问题，根据微信号会取到空白昵称]</param>
        /// <param name="_chatroom">群号</param>
        /// <param name="_msg">消息内容</param>
        public void SendAtMessage(string _wxid, string _chatroom, string _msg ) {
            Dictionary<string, object> _dic = new Dictionary<string, object>();
            _dic.Add("id", getId());
            _dic.Add("type", AT_MESSAGE);
            _dic.Add("content", _msg);
            _dic.Add("wxid", _wxid);
            _dic.Add("nickname", this.FindNickNameAtChatroomForId(_wxid,_chatroom));
            _dic.Add("roomid",_chatroom);
            Trace.WriteLine(JsonConvert.SerializeObject(_dic));
            Send(WeChatHelper, JsonConvert.SerializeObject(_dic));
        }

        /// <summary>
        /// 发送图片消息
        /// </summary>
        /// <param name="_wxid">微信号</param>
        /// <param name="_imagePath">图片地址(地址格式要转义)</param>
        public void SendImageMessage(string _wxid, string _imagePath) {
            Dictionary<string, object> _dic = new Dictionary<string, object>();
            _dic.Add("id", getId());
            _dic.Add("type", IMAGE_MESSAGE);
            _dic.Add("content",_imagePath);
            _dic.Add("wxid",_wxid);
            Trace.WriteLine(JsonConvert.SerializeObject(_dic));
            Send(WeChatHelper,JsonConvert.SerializeObject(_dic));
        }



        /// <summary>
        /// 获取所有群及群成员列表
        /// </summary>
        public void ChatroomUserList(String _chatroomId=null) {
            Dictionary<string, object> _dic = new Dictionary<string, object>();
            if (_chatroomId is null) {
                _dic.Add("id", getId());
                _dic.Add("type", CHATROOM_USER_LIST);
                _dic.Add("content", "op:list member");
                _dic.Add("wxid", "null");
            }
            else
            {
                _dic.Add("id", getId());
                _dic.Add("type", CHATROOM_USER_NAME);
                _dic.Add("content", _chatroomId);
                _dic.Add("wxid", "ROOT");
            }
            Trace.WriteLine(JsonConvert.SerializeObject(_dic));
            Send(WeChatHelper, JsonConvert.SerializeObject(_dic));
        }

        /// <summary>
        /// 设置调试标志
        /// </summary>
        /// <param name="_flg"></param>
        public void SetDebugInfo(Hook_Degbug_flg _flg = Hook_Degbug_flg.on) {
            Dictionary<string, object> _dic = new Dictionary<string, object>();
            _dic.Add("id", getId());
            _dic.Add("type", DEBUG_MESSAGE);
            _dic.Add("content", _flg.ToString());
            _dic.Add("wxid", "ROOT");
            Trace.WriteLine(JsonConvert.SerializeObject(_dic));
            Send(WeChatHelper, JsonConvert.SerializeObject(_dic));
        }

        public enum Hook_Degbug_flg
        {
            on,
            off,
        }


        /// <summary>
        /// 查询个人信息
        /// </summary>
        /// <param name="_wxid">wxid为空为查询登陆账号信息</param>
        private void requestUserInfo(string _wxid = null)
        {
            Dictionary<string, object> _dic = new Dictionary<string, object>();
            if (_wxid == null)
            {
                _dic.Add("id", getId().ToString());
                _dic.Add("type", PERSONAL_INFO);
                _dic.Add("content", "op:personal info");
                _dic.Add("wxid", "ROOT");

            }
            else
            {
                _dic.Add("id", getId().ToString());
                _dic.Add("type", USER_INFO);
                _dic.Add("content", "op:personal detail");
                _dic.Add("wxid", _wxid);

            }
            Trace.WriteLine(JsonConvert.SerializeObject(_dic));
            Send(WeChatHelper, JsonConvert.SerializeObject(_dic));

        }

        /// <summary>
        /// 个人信息
        /// </summary>
        /// <param name="_wxid">留空为登陆的信息</param>
        /// <returns></returns>
        public string GetUserInfo(string _wxid=null) {
            requestUserInfo(_wxid);
            Thread.Sleep(wait_for_request_user_info);
            return USERINFO;
        }



        /// <summary>
        /// 查看WebSocket连接状态
        /// </summary>
        public WebSocketState GetWebSocketStatus{
            get
            {
                return WeChatHelper.State;
            }
        }
        /// <summary>
        /// 获取微信版本
        /// </summary>
        /// <returns></returns>
        public string GetWeChatViersion()
        {
            return getModuleForProcess().FileVersionInfo.FileVersion;
        }


        /// <summary>
        /// 退出所有线程
        /// </summary>
        public void ExitAllSubThread() {
            System.Environment.Exit(0);
        }
    }
}
