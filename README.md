# wechat-bot  馈人玫瑰之手，历久犹有余香
目前支持微信2.9.0.123   
针对PC微信的个人机器人成品，学习使用，只提供DLL和客户端代码  
点整包下载或release，下载最新版本  
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

# 贡献

感谢 MickeyMi 贡献JAVA客户端代码  
感谢 ToBin    共享JAVA客户端代码  
感谢 诺阳     贡献C#客户端代码  
感谢 昆明-C#-SakuraYuki 贡献C#客户端代码  
感谢 Yangself666 贡献[java客户端代码](https://github.com/cixingguangming55555/wechat-bot/issues/60)   
感谢 tsingly 贡献python客户端代码   
# 微信版本

微信:[2.8.0.121](https://pan.baidu.com/s/1jrW2HzBxM8wceZRn8hT5UQ)   
提取码:ye2w   
微信:[2.9.0.123](https://pan.baidu.com/s/1zRJzwlZ1r8aRBeEc0lg1sw)   
提取码：j4m0   
# 开源
* [2.7.1.88内存获取用户信息](userlist.cpp)
# 整包下载
[整包下载](https://github.com/cixingguangming55555/wechat-bot/archive/4.5.7.73.zip)
# 文档
[开发文档](https://www.showdoc.cc/wechatbot)
# 声明
1、请大家在国家法律、法规和腾讯相关原则下使用  
2、不对任何下载和使用者的任何行为负责  
3、无任何后门、木马，也不获取、存储任何信息  
4、持续升级  
5、永久免费   
# DLL功能
0、DLL带websocket和HTTP服务，所有操作均通过websocket客户端和HTTP客户端进行  
1、客户端发送好友文本消息（支持websocket和HTTP）    
2、客户端获取通讯录好友wxid和名字(支持websocket和HTTP)  
3、客户端接收微信收到的文本消息  
4、客户端发送图片给好友（支持websocket和HTTP）   
5、发送AT消息（支持websocket和HTTP）  
6、发送附件（仅支持HTTP)   
7、获取chatroom成员列表(wxid)和昵称（支持websocket和HTTP）  
8、获取个人微信信息  
9、接收图片并存储到本地(默认路径:c:\temp\wechat)  
10、动态卸载DLL（支持HTTP和websocket)   
11、其它根据需求增加  
# FAQ
[问题帮助](./pic/help1.md)
# 注意
请参见client.js（websocket客户端）和httpclient.js（http客户端）示例代码   
注入一次即可，如要重新注入，请退出微信，重新启动微信后再注入  
发送文本消息时，需要先获取通讯录好友wxid和名字  
群ID是以@chatroom结尾的  
公众号是以gh开头的  
获取通讯录不是通过HOOK，是直接通过内存  
获取chatroom成员列表和昵称，不是通过HOOK，是直接通过内存  
# 客户端
1、C++客户端  
2、JS客户端  
3、其他无（大家可以贡献java\python\等客户端代码）  
# 交流
请扫码微信加好友，到时我会拉入群，备注：bot。空了我会处理的。

<center class="half">
    <img src="https://i.loli.net/2020/05/09/3m9cRatry4gNnqH.jpg" width="400"/>
</center>

# 请我喝咖啡

<center class="half">
    <img src="https://i.loli.net/2020/05/09/bPkaXrnVyzl6ewH.jpg" width="800"/>
</center>

# 致谢
感谢 MickeyMi 请我喝咖啡！  
感谢 vluoyue（罗月）请我喝咖啡！  
感谢 TedWang（微信） 请我喝咖啡！  
感谢 Frank(微信）  请我喝咖啡！  
感谢 doxsen(微信） 请我喝咖啡！  
感谢 南城诀、转身一生琉璃白 （微信）请我喝咖啡！  
感谢 小冰宝宝（微信）请我喝咖啡！  
感谢 伟大的大卫（微信） 请我喝咖啡！  
感谢 房客（微信） 请我喝咖啡！  
感谢 *阳 （微信） 请我喝咖啡!  
感谢 *瑞（微信） 请我喝咖啡！   
感谢 *灿（微信）请我喝咖啡！   
感谢 * doxsen(微信)请我喝咖啡   
感谢 * 🌜🌛(微信)请我喝咖啡   
感谢 * Joz(微信)请我喝咖啡   
感谢 * 净叶不沉 请我喝咖啡   
感谢 * 超人不会飞请我喝咖啡
