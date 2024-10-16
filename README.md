# Wechat-bot
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

# Notice
* 微信安全中心公告：https://mp.weixin.qq.com/s/9szvSZclomy5Pcq3Y-yH1A
  
![image](https://github.com/cixingguangming55555/wechat-bot/assets/61132896/72c9bd5e-7efc-4c15-9899-0ab76ff2aa39)
![image](https://github.com/cixingguangming55555/wechat-bot/assets/61132896/2b120879-bd53-4809-a597-071e410d1c2d)

# support：3.9.9.43，64bit，Tested only on Win11 Home Edition

# Usage

## server
```
start：run funtool or funtool -p port,default port is 5555

exit：CTRL + C

切记：不要在接收消息的时候退出

```
![image](https://github.com/cixingguangming55555/wechat-bot/assets/61132896/e296cfe6-05cf-4d86-bbb7-09b7574137ff)

## client
```
websocket：ws://127.0.0.1:5555/websocket 
http api（post)：
      http://127.0.0.1:5555/api/get_contact
      http://127.0.0.1:5555/api/get_chatroom  （获取群和群成员，群多的微信会崩溃）
      http://127.0.0.1:5555/api/get_chatroom_v1 (获取群和群成员索引:idx)
      http://127.0.0.1:5555/api/get_member      (根据get_chatroom_v1获取的idx，获取群成员的wxid，和http://127.0.0.1:5555/api/get_chatroom_v1搭配使用)
      http://127.0.0.1:5555/api/get_myself
      http://127.0.0.1:5555/api/send_txt（见http.js)
      http://127.0.0.1:5555/api/send_pic (见http.js)
      http://127.0.0.1:5555/api/get_nick (见http.js)
message type:
   886:anti revoke(not open)
   887:receive adn save image to path
```
## ChangeLog
* v0.0.93 heart beat support;disable auto update
## QQ group :103749758(1群已满） 812741469（2群）
