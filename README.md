# Wechat-bot 馈人玫瑰之手，历久犹有余香
<a href="https://github.com/cixingguangming55555/wechat-bot">
  <img align="center" src="https://github-readme-stats.vercel.app/api/pin/?username=cixingguangming55555&repo=wechat-bot" />
</a>
<a href="https://github.com/cixingguangming55555/wechat-bot">
  <img align="center" src="https://github-readme-stats.vercel.app/api/top-langs/?username=cixingguangming55555&layout=compact" />
</a>

<p align="center">
  <img src="https://i.loli.net/2020/05/09/HXClIf5A2EpUG4u.png" width="120">
</p>

<p align="center">
   <a href="https://github.com/cixingguangming55555/wechat-bot/blob/master/LICENSE">
    <img src="https://img.shields.io/github/license/cixingguangming55555/wechat-bot" alt="GitHub">
  </a>
  <a href="https://github.com/cixingguangming55555/wechat-bot/releases">
    <img src="https://img.shields.io/github/v/release/cixingguangming55555/wechat-bot?include_prereleases" alt="license">
  </a>
</p>

# 微信版本：3.9.2.23

# 新坑QQ群: 712370539

# 如何使用

## 服务器端
```
第一步 启动PC微信并登陆完成，微信的版本必须是：3.9.2.23

第二步 启动非注入版，funtool.exe

第三步 点启动即可
```
## 客户端
```
本质就是构造一个json，当然，http和websocket的json构造，还有一些区别，具体请去看  这两个文件：
websocket 客户端  ：client-3.2.1.121.js 
http  客户端示例：http-3.2.1.121.js 
```
### 发送文本消息示例--websocket
```javascript
function send_txt_msg()
{
  const j={
    id:getid(),
    type:TXT_MSG,
    wxid:'23023281066@chatroom',//roomid或wxid,必填
    roomid:'null',//此处为空
    content:'hello word',
    nickname:"null",//此处为空
    ext:'null'//此处为空
  };
  const s = JSON.stringify(j);
  return s;
}
```

### 发送文本消息示例--http
```javascript
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
  };
  const options =
  {
          url: url+'/api/sendtxtmsg',
          body:{
            para:jpara
        },
        json:true
  };
  let data = await rp(options);
  return data;
}
```
### 注意 
* 所有遇到的异常，都是因为json构造错误造成
* 切记，json里面,是7个配对的key和value，差1个都不行

## 多开请去此大佬处
https://github.com/crazyn2?tab=repositories

### 参考项目
* https://github.com/ChisBread/wechat-service
* 记得为这位大佬加星
