# wechat-bot  馈人玫瑰之手，历久犹有余香
针对PC微信的个人机器人成品，学习使用，只提供DLL和客户端代码  
点整包下载或release，下载最新版本  
# 贡献
感谢 MickeyMi 贡献JAVA客户端代码
# 版本
微信:2.8.0.121  
本品:2.2.2.56 
# 开源
* [2.7.1.88内存获取用户信息](userlist.cpp)
# 整包下载
[整包下载](https://github.com/cixingguangming55555/wechat-bot/archive/2.2.2.56.zip)
# 文档
[开发文档](https://www.showdoc.cc/wechatbot)
# 声明
1、请大家在国家法律、法规和腾讯相关原则下使用  
2、不对任何下载和使用者的任何行为负责  
3、无任何后门、木马，也不获取、存储任何信息  
4、持续升级  
5、永久免费   
# DLL功能
0、DLL带websocket服务，所有操作均通过websocket客户端进行  
1、客户端发送好友文本消息  
2、客户端获取通讯录好友wxid和名字  
3、客户端接收微信收到的文本消息  
4、客户端发送图片给好友  
5、发送AT消息  
6、获取chatroom成员列表(wxid),昵称暂无法对应  
7、获取个人微信信息  
8、其它根据需求增加  
# FAQ
[问题帮助](./pic/help1.md)
# 注意
注入一次即可，如要重新注入，请退出微信，重新启动微信后再注入  
发送文本消息时，需要先获取通讯录好友wxid和名字  
群ID是以@chatroom结尾的  
公众号是以gh开头的  
获取通讯录不是通过HOOK，是直接通过内存  
获取chatroom成员列表不是通过HOOK，是直接通过内存  
# 客户端
1、C++客户端  
2、JS客户端  
3、其他无（大家可以贡献java\python\等客户端代码）  
# License
[GPL](https://opensource.org/licenses/GPL-3.0)
# 交流
请扫码微信加好友，到时我会拉入群，备注：bot。空了我会处理的。

<center class="half">
    <img src="./pic/qrcode.jpg" width="400"/>
</center>

# 请我喝咖啡

<center class="half">
    <img src="./pic/38.jpg" width="400"/>
</center>

# 致谢
感谢 MickeyMi 请我喝咖啡！  
感谢 vluoyue（罗月）请我喝咖啡！  
