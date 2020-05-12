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
              wxid: 'zhanghua_cd',
              content: '今天我寒夜里看学飘过2338？？&&2222！'
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
    const j = await get_contact_list();
    console.log(j);
}

//console.log('test');
main();

