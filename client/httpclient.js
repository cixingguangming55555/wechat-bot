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
function getid()
{
   const id = Date.now();
   return id.toString();
}
async function send_at_msg()
{
    const options =
      {
          //method: 'GET',
          //url: 'https://apis.map.qq.com/ws/district/v1/list',
          url: url+'/api/sendatmsg',
          qs:
          {
              id: getid(),
              type: AT_MSG,
              roomid: '23023281066@chatroom',//the chatroom 
              wxid:'the wxid who you  want to send',
              content: '今天过来一起喝酒！同时，我们也发现',
              nick:'[微笑]Python'
          }
      };
      let data = await rp(options);
      const j = JSON.parse(data);
      
      //console.log(j.id); 
      //console.log(j.status);
      return j;


}
/**send_pic
 *  发送图片
 */
async function send_pic()
{
    const options =
      {
          //method: 'GET',
          //url: 'https://apis.map.qq.com/ws/district/v1/list',
          url: url+'/api/sendpic',
          qs:
          {
              id: getid(),
              type: PIC_MSG,
              wxid: 'filehelper',
              path: 'C:\\Users\\14988\\Desktop\\temp\\2.jpg'
          }
      };
      let data = await rp(options);
      const j = JSON.parse(data);
      
      //console.log(j.id); 
      //console.log(j.status);
      return j;


}

/**get_member_nick
 * 获取群成员昵称
 */

async function get_member_nick()
{
    //getmembernick
    const options =
      {
          
          url: url+'/api/getmembernick',
          qs:
          {
              id: getid(),
              type: CHATROOM_MEMBER_NICK,
              roomid: '17339716569@chatroom'//1280641435@chatroom
          }
      };
    const data = await rp(options);
    const j = JSON.parse(data);
    
    //console.log(j.id); 
    //console.log(j.status);
    return j;
}
/**get_getmemberid
 *   获取群成员id
 */
async function get_memberid()
{
    const options={
        url: url+'/api/getmemberid'
    };
    let data = await rp(options);
    const j = JSON.parse(data);
    
    //console.log(j.id); 
    //console.log(j.status);
    return j;
}

/**get_contact_list  获取好友和群列表
 * 
 */
async function get_contact_list()
{
    const options={
        url: url+'/api/getcontactlist'
    };
    let data = await rp(options);
    const j = JSON.parse(data);
    
    //console.log(j.id); 
    //console.log(j.status);
    return j;

}
/**
 * send txt message
 */
async function sendtxt()
{
    const options =
      {
          //method: 'GET',
          //url: 'https://apis.map.qq.com/ws/district/v1/list',
          url: url+'/api/sendtxtmsg',
          qs:
          {
              id: getid(),
              type: TXT_MSG,
              wxid: 'filehelper',
              content: '今天我寒夜里看学飘过2338？？&&2222！'
          }
      };
      let data = await rp(options);
      const j = JSON.parse(data);
      
      //console.log(j.id); 
      //console.log(j.status);
      return j;


}
/**send_attatch
 * send the attatchment
 */
async function send_attatch()
{
    const options =
      {
          //method: 'GET',
          //url: 'https://apis.map.qq.com/ws/district/v1/list',
          url: url+'/api/sendattatch',
          qs:
          {
              id: getid(),
              //type: TXT_MSG,
              wxid: '23023281066@chatroom',
              filepath: 'C:\\temp\\wechat.txt'
          }
      };
      let data = await rp(options);
      const j = JSON.parse(data);
      
      //console.log(j.id); 
      //console.log(j.status);
      return j;
}

async function refresh_memberlist()
{
    const options =
      {
          //method: 'GET',
          //url: 'https://apis.map.qq.com/ws/district/v1/list',
          url: url+'/api/refresh_chatroom',
          qs:
          {
              id: getid(),
              wxid: 'null',
              content: 'null'
          }
      };
      let data = await rp(options);
      const j = JSON.parse(data);
      
      //console.log(j.id); 
      //console.log(j.status);
      return j;
}
async function send_destroy()
{
    const options =
      {
          //method: 'GET',
          //url: 'https://apis.map.qq.com/ws/district/v1/list',
          url: url+'/api/destroy',
          qs:
          {
              id: getid(),
              wxid: 'null',
              content: 'null'
          }
      };
      let data = await rp(options);
      const j = JSON.parse(data);
      
      //console.log(j.id); 
      //console.log(j.status);
      return j;
}

async function main()
{
    //const j = await get_contact_list();
    //const j = await get_memberid();
    //const j = await get_member_nick();
    //const j = await send_at_msg();
    //const j = await send_attatch();
    //console.log(j);
    //await send_destroy();
    await refresh_memberlist();
}

//console.log('test');
main();

