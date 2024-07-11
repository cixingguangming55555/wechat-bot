/****************************************
 * 重要：只接受websocket的消息：
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







ws.on('open', function open() 
{
 
  
});

ws.on('close', function close() {
  console.log('disconnected');
});

ws.on('message', function incoming(data) 
{

  console.log(data);
  return;
  }
  
});
