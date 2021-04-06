/****************************************
 * 重要：3.2.1.121，ws客户端已经改变调用方式，具体如下：
 * get_chat_nick_p()
 * get_contact_list()
 * get_chatroom_memberlist()
 * send_at_msg()
 * send_attatch()
 * send_txt_msg()
 * send_pic_msg()
 * get_personal_info()
 * ***************************************/
const WebSocket = require('ws');
const ws = new WebSocket('ws://127.0.0.1:5555');

const HEART_BEAT = 5005;
const RECV_TXT_MSG = 1;
const RECV_PIC_MSG = 3;
const USER_LIST = 5000;
const GET_USER_LIST_SUCCSESS = 5001;
const GET_USER_LIST_FAIL     = 5002;
const TXT_MSG = 555;
const PIC_MSG = 500;
const AT_MSG = 550;
const CHATROOM_MEMBER = 5010;
const CHATROOM_MEMBER_NICK = 5020;
const PERSONAL_INFO = 6500;
const DEBUG_SWITCH = 6000;
const PERSONAL_DETAIL =6550;
const DESTROY_ALL = 9999;
const NEW_FRIEND_REQUEST=37;//微信好友请求消息
const AGREE_TO_FRIEND_REQUEST=10000;//同意微信好友请求消息
const ATTATCH_FILE = 5003;




function getid()
{
   const id = Date.now();
   return id.toString();
}
function get_chat_nick_p(s_wxid,s_roomid)
{

  const j={
    id:getid(),
    type:CHATROOM_MEMBER_NICK,
    wxid:s_wxid,
    roomid:s_roomid,
    content:'null',
    nickname:"null",
    ext:'null'

    
  };
  const s= JSON.stringify(j);
  return s;

}
function get_chat_nick()
{
  /*const j={
    id:getid(),
    type:CHATROOM_MEMBER_NICK,
    content:'23023281066@chatroom',//chatroom id 23023281066@chatroom  17339716569@chatroom
    //5325308046@chatroom
    //5629903523@chatroom
    wxid:'ROOT'
  };*/
  const s= JSON.stringify(j);
  return s;
}

function handle_nick(j){
    const data = j.content;
    let i = 0;
    for(const item of data)
    {
        console.log(i++,item.nickname)
    }
}
function handle_memberlist(j)
{
   const data = j.content;
   let i =0;
   //get_chat_nick_p(j.roomid);
   for(const item of data)
   {
      console.log("---------------",item.room_id,"--------------------");  
      //console.log("------"+item.roomid+"--------");
      //ws.send(get_chat_nick_p(item.roomid));
      const memberlist=item.member;
      
      //console.log("hh",item.address,memberlist);
      
      //const len = memberlist.length();
      //console.log(memberlist);
      for(const m of memberlist)
      {
          console.log(m);//获得每个成员的wxid
      }
      /*for(const n of nicklist)//目前不建议使用
      {
        console.log(n);//获得每个成员的昵称，注意，没有和wxi对应的关系
      }*/
   }
}
function get_chatroom_memberlist()
{
  const j={
    id:getid(),
    type:CHATROOM_MEMBER,
    roomid:'null',//null
    wxid:'null',//not null
    content:'null',//not null
    nickname:'null',
    ext:'null'
  };

  const s= JSON.stringify(j);
  return s;
}
function send_attatch()
{
  /*const j={
    id:getid(),
    type:ATTATCH_FILE,
    content:'C:\\tmp\\log.txt',
    wxid:'23023281066@chatroom'
  };*/
  const j={
    id:getid(),
    type:ATTATCH_FILE,
    wxid:'23023281066@chatroom',//roomid或wxid,必填
    roomid:'null',//此处为空
    content:'C:\\tmp\\log.7z',
    nickname:"null",//此处为空
    ext:'null'//此处为空
    //wxid:'22428457414@chatroom'
    
  };
  const s = JSON.stringify(j);
  return s;
}
function send_at_msg()
{
  const j={
    id:getid(),
    type:AT_MSG,
    roomid:'23023281066@chatroom',//not null  23023281066@chatroom
    wxid:'your wxid',//not null
    content:'at msg test,hello world，真的有一套',//not null
    nickname:'老张',
    ext:'null'
  };
  
  const s = JSON.stringify(j);
  return s;
}

function send_pic_msg()
{
  const j={
    id:getid(),
    type:PIC_MSG,
    wxid:'23023281066@chatroom',
    roomid:'null',
    content:'C:\\tmp\\2.jpg',
    nickname:"null",
    ext:'null'
    //wxid:'22428457414@chatroom'
    
  };
  
  const s = JSON.stringify(j);
  //console.log(s);
  return s; 
}
function get_personal_detail()
{
  /*const j={
    id:getid(),
    type:PERSONAL_DETAIL,
    content:'op:personal detail',
    wxid:'zhanghua_cd'
  };*/
  const s = JSON.stringify(j);
  return s;
}
/**
 * send_txt_msg : 发送消息给好友
 * 
 */
function get_personal_info()
{
  const j={
    id:getid(),
    type:PERSONAL_INFO,
    wxid:'null',
    roomid:'null',
    content:'null',
    nickname:"null",
    ext:'null'
    //wxid:'22428457414@chatroom'
    
  };
  const s = JSON.stringify(j);
  return s;
}
function send_txt_msg()
{

  //必须按照该json格式，否则服务端会出异常
  const j={
    id:getid(),
    type:TXT_MSG,
    wxid:'23023281066@chatroom',//roomid或wxid,必填
    roomid:'null',//此处为空
    content:'hello word',
    nickname:"null",//此处为空
    ext:'null'//此处为空
    //wxid:'22428457414@chatroom'
    
  };
  /*const j={
    id:getid(),
    type:TXT_MSG,
    content:'hello world',//文本消息内容
    
  };*/
  const s = JSON.stringify(j);
  return s;
}
/**
 * send_wxuser_list  : 获取微信通讯录用户名字和wxid
*/
function get_contact_list()
{
  /*const j={
    id:getid(),
    type:USER_LIST,
    content:'user list',
    wxid:'null'
  };*/

  const j={
    id:getid(),
    type:USER_LIST,
    roomid:'null',//null
    wxid:'null',//not null
    content:'null',//not null
    nickname:'null',
    ext:'null'
  };
  const s = JSON.stringify(j);
 //console.log(s);
  return s;
}
/**
 * handle_wxuser_list  : websocket返回的用户信息
 * @param {*} j json数组
 *              数组里面的wxid，要保存下来，供发送微信的时候用
 * 
 */
function handle_wxuser_list(j)
{
   const j_ary = j.content;
   var i = 0;
   for(const item of j_ary)
   {
      i=i+1;
      const id = item.wxid;
      const m = id.match(/@/);
      if(m!=null){
        //console.log(id);
        console.log(item.wxid,item.name);
      }
      //console.log(m);
      //
   }
}
/**
 * 
 * @param {*} j json对象
 */
function handle_recv_msg(j)
{
   
   /*const content = j.content;
   const wxid =j.wxid;
   const sender = j.sender;
   consoconsole.log(j);le.log('接收人:'+wxid);
   console.log('内容：'+content);
   console.log('发送人：'+sender);*///如果为空，那就是你自己发的
   console.log(j);
}

function heartbeat(j)
{
   console.log(j);
   //console.log(utf16ToUtf8(wxid),utf16ToUtf8(name));
}

ws.on('open', function open() 
{
  ws.send(get_personal_info());
  //ws.send(get_contact_list());
  //ws.send(send_attatch());
  //ws.send("hello world");
  //ws.send(destroy_all());
  //ws.send(get_chat_nick_p("zhanghua_cd","23023281066@chatroom"));
  //for(const item of roomid_list)
  //{
    //console.log(item);
    //ws.send(get_chat_nick_p(item));
  //}
  //ws.send(get_chat_nick());
  //ws.send(get_personal_info());
  //ws.send(send_pic_msg());
  //ws.send(send_txt_msg());
  //ws.send(get_chatroom_memberlist());
  //ws.send(send_at_msg());

  //ws.send(get_personal_detail());
  //ws.send(debug_switch()
  //ws.send(send_wxuser_list());
  //ws.send(send_txt_msg());
  
  /** 获取chatroom 成员昵称
   * ws.send(get_chat_nick());
   */

  /**  通过wxid获取好友详细细腻
   * ws.send(get_personal_detail());
   */

  /** debugview调试信息开关，默认为关
   * ws.send(debug_switch());
   */

  /** 获取微信个人信息
   * ws.send(get_personal_info());
   */

  /** 获取群好友列表
   * ws.send(get_chatroom_memberlist());
   */

  /** 发送群AT消息
   * ws.send(send_at_msg());
   */

  /**获取微信通讯录好友列表
   * ws.send(send_wxuser_list());
   */
  /** 向你的好友发送微信文本消息
   * ws.send(send_txt_msg());
   */
   
   /**向你的好友发送图片
    * ws.send(send_pic_msg());
    */
  /*发送信息调用上面两个函数即可，可自行改造*/

  //ws.send(send_pic_msg());
  //ws.send(send_txt_msg());
  
});

ws.on('close', function close() {
  console.log('disconnected');
});

ws.on('message', function incoming(data) 
{
  //break;
  //return;
  console.log(data);
  //ws.send("hello world");
  return;
  const j = JSON.parse(data);
  //console.log(j);
  const type = j.type;
  switch(type)
  {
    case CHATROOM_MEMBER_NICK:
      console.log(j);
      //handle_nick(j);
      break;
    case PERSONAL_DETAIL:
      console.log(j);
      break;
    case AT_MSG:
      console.log(j);
      break;
    case DEBUG_SWITCH:
      console.log(j);
      break;
    case PERSONAL_INFO:
      console.log(j);
      break;
    case TXT_MSG:
      console.log(j);
      break;
    case PIC_MSG:
      console.log(j);
      break;
    case CHATROOM_MEMBER:
      //console.log(j);
      handle_memberlist(j);
      break;
    case RECV_PIC_MSG:
        handle_recv_msg(j);
        break;
    case RECV_TXT_MSG:
      handle_recv_msg(j);
    break;
    case HEART_BEAT:
      heartbeat(j);
    break;
    case USER_LIST:
      console.log(j);
      //handle_wxuser_list(j);
      break;
    case GET_USER_LIST_SUCCSESS:
      handle_wxuser_list(j);
      break;
    case GET_USER_LIST_FAIL:
      handle_wxuser_list(j);
      break;
     case NEW_FRIEND_REQUEST:
       //console.log("---------------37----------");
       console.log(j);
       break;
     case AGREE_TO_FRIEND_REQUEST:
      console.log("---------------25----------");
      console.log(j);
      break;
    //case SEND_TXT_MSG_SUCCSESS:
      //handle_recv_msg(j);
      //break;
    //case SEND_TXT_MSG_FAIL:
      //handle_recv_msg(j);
      //break;
    default:
      break;
  }
  //console.log(`Roundtrip time: ${Date.now() - data} ms`);

  /*setTimeout(function timeout() {
    ws.send(Date.now());
  }, 500);*/
});
