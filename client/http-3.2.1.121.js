/****************************************
 * 重要：3.2.1.121，http的客户端已经改变调用方式
 * get_chatroom_member_list()
 * get_contact_list() 
 * send_txt_msg()
 * send_at_msg()
 * send_pic()
 * send_attatch()
 * get_member_nick()
 * get_personal_info()
 * ***************************************/

const rp = require('request-promise');
const url = 'http://127.0.0.1:5555';
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
const ATTATCH_FILE = 5003;


function getid()
{
   const id = Date.now();
   return id.toString();
}
async function send_at_msg()
{
  const jpara={
    id:getid(),
    type:AT_MSG,
    roomid:'your roomid',//not null  23023281066@chatroom
    wxid:'your wxid',//not null
    content:'at msg test,hello world，真的有一套',//not null
    nickname:'your nickname',
    ext:'null'
  };  
  const options =
      {
          //method: 'GET',
          //url: 'https://apis.map.qq.com/ws/district/v1/list',
          url: url+'/api/sendatmsg',
          body:{
            para:jpara
        },
        json:true
      };
      let data = await rp(options);
      //const j = JSON.parse(data);
      
      //console.log(j.id); 
      //console.log(j.status);
      return data;


}
/**send_pic
 *  发送图片
 */
async function send_pic()
{
  const jpara={
    id:getid(),
    type:PIC_MSG,
    wxid:'your id(wxid or roomid)',//23023281066@chatroom
    roomid:'null',
    content:'C:\\tmp\\2.jpg',
    nickname:"null",
    ext:'null'
    //wxid:'22428457414@chatroom'
    
  };
  
    const options =
      {
          //method: 'GET',
          //url: 'https://apis.map.qq.com/ws/district/v1/list',
          url: url+'/api/sendpic',
          body:{
            para:jpara
        },
        json:true
      };
      let data = await rp(options);
      //const j = JSON.parse(data);
      
      //console.log(j.id); 
      //console.log(j.status);
      return data;


}

/**get_member_nick
 * 获取群成员昵称
 */

async function get_member_nick(wx_id,roomid)
{

      const jpara={
        id:getid(),
        type:CHATROOM_MEMBER_NICK,
        wxid:'your wxid',
        roomid:'your roomid',//23023281066@chatroom
        content:'null',
        nickname:"null",
        ext:'null'
        //wxid:'22428457414@chatroom'
        
      };
    const options =
      {
          
          url: url+'/api/getmembernick',
          body:{
            para:jpara
        },
        json:true
      };
    const data = await rp(options);
    //const j = JSON.parse(data);
    
    //console.log(j.id); 
    //console.log(j.status);
    return data;
}
/**get_getmemberid
 *   获取群成员id
 */
async function get_memberid()
{

    const jpara={
        id:getid(),
        type:CHATROOM_MEMBER,
        wxid:'null',
        content:'op:list member'
      };


    const options={
        url: url+'/api/getmemberid',
        body:{
            para:jpara
        },
        json:true
    };
    let data = await rp(options);
    //const j = JSON.parse(data);
    
    //console.log(j.id); 
    //console.log(j.status);
    return data;
}

/**get_contact_list  获取好友和群列表
 * 
 */
async function get_contact_list()
{
  const jpara={
    id:getid(),
    type:USER_LIST,
    roomid:'null',//null
    wxid:'null',//not null
    content:'null',//not null
    nickname:'null',
    ext:'null'
  };
    const options={
        url: url+'/api/getcontactlist',
        body:{
            para:jpara
        },
        json:true
    };
    let data = await rp(options);
    //const j = JSON.parse(data);
    
    //console.log(j.id); 
    //console.log(j.status);
    return data;

}
async function get_chatroom_member_list()
{
  const jpara={
    id:getid(),
    type:CHATROOM_MEMBER,
    roomid:'null',//null
    wxid:'null',//not null
    content:'null',//not null
    nickname:'null',
    ext:'null'
  };
    const options={
        url: url+'/api/get_charroom_member_list',//
        body:{
            para:jpara
        },
        json:true
    };
    let data = await rp(options);
    //const j = JSON.parse(data);
    
    //console.log(j.id); 
    //console.log(j.status);
    return data;

}
/**
 * send txt message
 */
async function send_txt_msg()
{
  const jpara={
    id:getid(),
    type:TXT_MSG,
    wxid:'23023281066@chatroom',//roomid或wxid,必填
    roomid:'null',//此处为空
    content:'hello word',
    nickname:"null",//此处为空
    ext:'null'//此处为空
    //wxid:'22428457414@chatroom'
    
  };
    const options =
      {
          //method: 'GET',
          //url: 'https://apis.map.qq.com/ws/district/v1/list',
          url: url+'/api/sendtxtmsg',
          body:{
            para:jpara
        },
        json:true
      };
      let data = await rp(options);
      //const j = JSON.parse(data);
      
      //console.log(j.id); 
      //console.log(j.status);
      return data;


}
/**send_attatch
 * send the attatchment
 */
async function send_attatch()
{


      const jpara={
        id:getid(),
        type:ATTATCH_FILE,
        wxid:'23023281066@chatroom',//roomid或wxid,必填
        roomid:'null',//此处为空
        content:'C:\\tmp\\log.7z',
        nickname:"null",//此处为空
        ext:'null'//此处为空
        //wxid:'22428457414@chatroom'
        
      };
    const options =
      {
          //method: 'GET',
          //url: 'https://apis.map.qq.com/ws/district/v1/list',
          url: url+'/api/sendattatch',
          body:{
            para:jpara
        },
        json:true
       
      };
      let data = await rp(options);
      //const j = JSON.parse(data);
      
      //console.log(j.id); 
      //console.log(j.status);
      return data;
}


async function get_personal_info()
{


  const jpara={
    id:getid(),
    type:PERSONAL_INFO,
    wxid:'null',
    roomid:'null',
    content:'null',
    nickname:"null",
    ext:'null'
    
  };
    const options =
      {
          url: url+'/api/get_personal_info',
          body:{
            para:jpara
        },
        json:true
       
      };
      let data = await rp(options);
      return data;
}



async function main()
{
    //const j = await get_contact_list();
    //const j = await get_chatroom_member_list();
    //const j = await send_txt_msg();
    //const j = await get_member_nick("zhanghua_cd","23023281066@chatroom");
    //const j = await send_at_msg();
    //const j = await send_attatch();
    //const j = await get_member_nick();
    //console.log(j);
    //await send_destroy();
    //await refresh_memberlist();
    //console.log("test begin");
    //const j = await send_destroy();
    //const j = await send_attatch();
    //const j = await send_test();
    const j = await get_personal_info();
    console.log(j);
}

//console.log('test');
main();
