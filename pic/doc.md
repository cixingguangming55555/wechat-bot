# 服务端口配置
* 13版本后，会自动在c:\temp\wechat\下生成一个config.ini文件。port代表websocket的端口。修改后需要退出微信，重新注入才能生效。
# 使用
## 第一步：安装对应微信版本，如DLL文件名为：3.2.1.121-0.0.0.013.dll,则应该安装微信3.2.1.121。切记，版本一定要对应上；
## 第二步：启动微信并登陆；
## 第三步：注入。使用client目录下的:微信DLL注入器V1.0.3.exe（和DLL放一个目录）。启动exe，点击注入。
# 开发（js为例）
## 第一步：get_contact_list()，获取通讯录信息
## 第二步:get_chatroom_member_list(),获取群成员信息
## 第三步：在此基础上，可以用获取的的wxid，进行发送文本等操作
### 说明
```
 * get_contact_list() //获取通讯录好友信息
 * get_chatroom_member_list()  //获取群成员信息
 * send_txt_msg() //对好友或群发送文本消息
 * send_at_msg()  //对群发送at消息
 * send_pic() //发送图片
 * send_attatch() //发送附件
 * get_member_nick()  //获取群成员昵称
```
###
### 重要1，参数传递
* 切记，jpara是放在body里面的，即所有传递的参数是放body里面的,para这个key也不能改
```
const options =
      {
          url: url+'/api/sendatmsg',
          body:{
            para:jpara
        },
        json:true
      };
```
### 重要2，参数传递
* jpara里面构造的每一个key都必须存在，不能多也不能少
```
const jpara={
    id:getid(),
    type:AT_MSG,
    roomid:'your roomid ',//not null
    wxid:'your wxid',//not null
    content:'your content',//not null
    nickname:'your nickname',//not null
    ext:'null'
  };  
```
