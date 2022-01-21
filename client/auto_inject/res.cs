using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace weBot.UI
{

    public partial class Main : Form
    {
        [DllImport("kernel32.dll")]
        public static extern int VirtualAllocEx(IntPtr hwnd, Int32 lpaddress, int size, int type, Int32 tect);
        [DllImport("kernel32.dll")]
        public static extern Boolean WriteProcessMemory(IntPtr hwnd, int baseaddress, string buffer, int nsize, int filewriten);
        [DllImport("kernel32.dll")]
        public static extern int GetProcAddress(int hwnd, string lpname);
        [DllImport("kernel32.dll")]
        public static extern int GetModuleHandleA(string name);
        [DllImport("kernel32.dll")]
        public static extern IntPtr CreateRemoteThread(IntPtr hwnd, int attrib, int size, int address, int par, int flags, int threadid);
        [DllImport("kernel32.dll")]
        public static extern Int32 WaitForSingleObject(IntPtr hHandle, UInt32 dwMilliseconds);
        [DllImport("kernel32.dll")]
        public static extern Boolean VirtualFree(IntPtr lpAddress, Int32 dwSize, Int32 dwFreeType);

        UInt32 INFINITE = 0xFFFFFFFF;
        Int32 MEM_COMMIT = 0x1000;
        Int32 MEM_RESERVE = 0x2000;
        Int32 MEM_RELEASE = 0x8000;
        Int32 PAGE_EXECUTE_READWRITE = 0x40;

        IntPtr hwnd;
        Int32 loadaddr;
        Int32 AllocBaseAddress;
        IntPtr ThreadHwnd;
        Thread t;
        bool state = false;
        delegate void Change(string text);

        public Main()
        {
           
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(button1.Text == "启动他")
            {
                t = new Thread(new ThreadStart(StartWorkComeOn));
                state = true;
                button1.Text = "停止他";
                t.Start();//启动他
            }
            else
            {
                state = false;
                button1.Text = "启动他";
                t.Abort();
            }
            
            
        }
        private void Settext(string text)
        {
            button1.Text = text;
        }
        private void StartWorkComeOn()
        {
            string path = System.AppDomain.CurrentDomain.BaseDirectory;
            string dllname = path + "auto.dll";
            if (!File.Exists(dllname))
            {
                MessageBox.Show("文件不在，或者没有改名为auto.dll");
                this.BeginInvoke(new Change(Settext), "启动他");
               
                return;
            }
            while (true)//上死循环，干他！
            {
                Process[] ObjModulesList = Process.GetProcessesByName("WeChat");
                if(ObjModulesList.Length > 0)   //检查到有微信进程，准备注入
                {
                    hwnd = ObjModulesList[0].Handle;    // 暂时只能自动注入第一个微信，多开的没想好怎么自动注入他
                    bool h = false;
                    foreach (Process prc in ObjModulesList)     //可能多开，所有每个符合条件的都遍历一遍
                    {
                        ProcessModuleCollection ObjModules = prc.Modules;
                        foreach (ProcessModule objModule in ObjModules) //注入前遍历一遍是否已经被注入过，被注入过就不干他了
                        {
                            string strModulePath = objModule.FileName.ToString();
                            if(dllname == strModulePath)
                            {
                                h = true;
                                Console.WriteLine("已注入");
                            }
                           
                        }
                    }
                    if (!h)  //判断完微信是否被注入过之后，就开始操作了！
                    {
                        AllocBaseAddress = VirtualAllocEx(hwnd, 0, dllname.Length + 1, MEM_COMMIT + MEM_RESERVE, PAGE_EXECUTE_READWRITE);
                        bool ok = WriteProcessMemory(hwnd, AllocBaseAddress, dllname, dllname.Length + 1, 0);
                        if (!ok)
                        {
                            MessageBox.Show("申请内存失败了，活没法继续干"); break; //结束死循环，自动终止线程;
                        }
                        loadaddr = GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
                        ThreadHwnd = CreateRemoteThread(hwnd, 0, 0, loadaddr, AllocBaseAddress, 0, 0);
                        
                        WaitForSingleObject(ThreadHwnd, INFINITE);
                        Console.WriteLine("活干好了");
                        VirtualFree(hwnd, 0, MEM_RELEASE);//干完活了把申请到的内存释放掉
                    }
                    else
                    {
                        Console.WriteLine("检测到已注入不做任何处理，循环一直开着，可以为下次启动做准备");
                       
                    }
                }
                Thread.Sleep(1000);//线程暂停1秒继续死循环
            }
        }

        private void Main_Load(object sender, EventArgs e)
        {

        }

        private void Main_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (state)
            {
                t.Abort();
            }
            
        }
    }
}
