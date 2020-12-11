/**
 * 1、先获得好友和群的信息
 *    ws.send(send_wxuser_list());
 *    这里面有好友的wxid和群的roomid
 * 2、然后可以调用
 *    //ws.send(send_pic_msg());
      //ws.send(send_txt_msg());
      //ws.send(send_at_msg());
   3、群成员和昵称：
      ws.send(get_chat_nick_p("22049764763@chatroom"));
 */

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
const CHATROOM_MEMBER = 5010;//
const CHATROOM_MEMBER_NICK = 5020;
const PERSONAL_INFO = 6500;
const DEBUG_SWITCH = 6000;
const PERSONAL_DETAIL =6550;
const DESTROY_ALL = 9999;
const NEW_FRIEND_REQUEST=37;//微信好友请求消息
const AGREE_TO_FRIEND_REQUEST=10000;//同意微信好友请求消息


function getid()
{
   const id = Date.now();
   return id.toString();
}
function get_chat_nick_p(roomid)
{
  const j={
    id:getid(),
    type:CHATROOM_MEMBER_NICK,
    content:roomid,//chatroom id 23023281066@chatroom  17339716569@chatroom
    //5325308046@chatroom
    //5629903523@chatroom
    wxid:'ROOT'
  };
  const s= JSON.stringify(j);
  return s;

}
function get_chat_nick()
{
  const j={
    id:getid(),
    type:CHATROOM_MEMBER_NICK,
    content:'31252583242@chatroom',//chatroom id 23023281066@chatroom  17339716569@chatroom
    //5325308046@chatroom
    //5629903523@chatroom
    wxid:'ROOT'
  };
  const s= JSON.stringify(j);
  return s;
}
function debug_switch()
{
   const j={
     id:getid(),
     type:DEBUG_SWITCH,
     content:'off',//on,off
     wxid:'ROOT'
   };
   const s= JSON.stringify(j);
   return s;

}
function handle_nick(j){
    const data = j.content;
    let i = 0;
    for(const item of data)
    {
        //console.log(i++,item.nickname)
    }
}
function handle_memberlist(j)//废弃
{
   const data = j.content;
   let i =0;
   //get_chat_nick_p(j.roomid);
   for(const item of data)
   {
      console.log(i++,item.roomid);  
    //console.log("------"+item.roomid+"--------");
      //ws.send(get_chat_nick_p(item.roomid));
      const memberlist=item.member;
      //const len = nicklist.length();
      //console.log(len);
      //if(item.roomid == "23023281066@chatroom"){
      for(const m of memberlist)
        {
          console.log(m);//获得每个成员的wxid
        }
      //}//
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
    wxid:'null',
    content:'op:list member'
  };

  const s= JSON.stringify(j);
  return s;
}
function send_at_msg()
{
  const j={
    id:getid(),
    type:AT_MSG,
    roomid:'23023281066@chatroom',//not null
    wxid:'wxid',//not null
    content:'今天过来一起喝酒！',//not null
    nickname:'[微笑]Python'
  };
  
  const s = JSON.stringify(j);
  return s;
}
function destroy_all()
{
  const j={
    id:getid(),
    type:DESTROY_ALL,
    content:'none',
    //wxid:'22428457414@chatroom'
    wxid:'none'
  };
  
  const s = JSON.stringify(j);
  console.log(s);
  return s; 
}
function send_pic_msg()
{
  const j={
    id:getid(),
    type:PIC_MSG,
    content:'C:\\Users\\14988\\Desktop\\temp\\2.jpg',
    //wxid:'22428457414@chatroom'
    //wxid:'22428457414@chatroom'
    wxid:'filehelper'
  };
  
  const s = JSON.stringify(j);
  console.log(s);
  return s; 
}
function get_personal_detail()
{
  const j={
    id:getid(),
    type:PERSONAL_DETAIL,
    content:'op:personal detail',
    wxid:'wxid_nk2gsh27qlen21'
  };
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
    content:'op:personal info',
    wxid:'ROOT'
  };
  const s = JSON.stringify(j);
  return s;
}
function send_txt_msg()
{
  const j={
    id:getid(),
    type:TXT_MSG,
    content:'hello world',//文本消息内容
    wxid:'leader318'//wxid  21527280818@chatroom
  };
  const s = JSON.stringify(j);
  return s;
}
/**
 * send_wxuser_list  : 获取微信通讯录用户名字和wxid
*/
function send_wxuser_list()
{
  const j={
    id:getid(),
    type:USER_LIST,
    content:'user list',
    wxid:'null'
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
        console.log(i,item.wxid,item.name);
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
   console.log(j.content);
   //console.log(utf16ToUtf8(wxid),utf16ToUtf8(name));
}
ws.on('open', function open() 
{
  //ws.send(get_chatroom_memberlist());
  ws.send(destroy_all());
  //ws.send(get_chat_nick_p("4865049815@chatroom"));
  //for(const item of roomid_list)
  //{
    //console.log(item);
    //ws.send(get_chat_nick_p(item));
  //}
  //ws.send(get_chat_nick());
  //ws.send(get_personal_info());
  //ws.send(send_pic_msg());
  //ws.send(send_txt_msg());
  //ws.send(send_at_msg());

  //ws.send(get_personal_detail());
  //ws.send(debug_switch());
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
  const j = JSON.parse(data);
  console.log(j);
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
    case CHATROOM_MEMBER://废弃，请使用CHATROOM_MEMBER_NICK 2020/12/06
      console.log(j);
      //handle_memberlist(j);
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
      //console.log(j);
      handle_wxuser_list(j);
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