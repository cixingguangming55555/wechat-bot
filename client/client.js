/**
 * 
 */

const WebSocket = require('ws');
const ws = new WebSocket('ws://127.0.0.1:5555');

const HEART_BEAT = 5005;
const RECV_TXT_MSG = 1;
const USER_LIST = 5000;
const GET_USER_LIST_SUCCSESS = 5001;
const GET_USER_LIST_FAIL     = 5002;
const TXT_MSG = 555;
const SEND_TXT_MSG_SUCCSESS = 556;
const SEND_TXT_MSG_FAIL     = 557;


function getid()
{
   const id = Date.now();
   return id.toString();
}
/**
 * send_txt_msg : 发送消息给好友
 * 
 */
function send_txt_msg()
{
  const j={
    id:getid(),
    type:TXT_MSG,
    content:'hello,欢迎使用本软件，有问题请联系1498814665@qq.com或加QQ，备注：机器人',//文本消息内容
    wxid:'filehelper'//wxid
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
   for(const item of j_ary)
   {
      console.log(item.wxid,item.name);
   }
}
/**
 * 
 * @param {*} j json对象
 */
function handle_recv_msg(j)
{
   
   const content = j.content;
   const wxid =j.wxid;
   const sender = j.sender;

   console.log('接收人:'+wxid);
   console.log('内容：'+content);
   console.log('发送人：'+sender);//如果为空，那就是你自己发的
}

function heartbeat(j)
{
   console.log(j.content);
   //console.log(utf16ToUtf8(wxid),utf16ToUtf8(name));
}
ws.on('open', function open() 
{
  /**获取微信通讯录好友列表
   * ws.send(send_wxuser_list());
   */
  /** 向你的好友发送微信文本消息
   * ws.send(send_txt_msg());
   */
   
  /*发送信息调用上面两个函数即可，可自行改造*/
  
});

ws.on('close', function close() {
  console.log('disconnected');
});

ws.on('message', function incoming(data) 
{
  
  const j = JSON.parse(data);
  const type = j.type;
  switch(type)
  {
    case RECV_TXT_MSG:
      handle_recv_msg(j);
    break;
    case HEART_BEAT:
      heartbeat(j);
    break;
    case GET_USER_LIST_SUCCSESS:
      handle_wxuser_list(j);
      break;
    case GET_USER_LIST_FAIL:
      handle_wxuser_list(j);
      break;
    case SEND_TXT_MSG_SUCCSESS:
      handle_recv_msg(j);
      break;
    case SEND_TXT_MSG_FAIL:
      handle_recv_msg(j);
      break;
    default:
      break;
  }
  //console.log(`Roundtrip time: ${Date.now() - data} ms`);

  /*setTimeout(function timeout() {
    ws.send(Date.now());
  }, 500);*/
});