# wechat-bot 馈人玫瑰之手，历久犹有余香

<p align="center">
  <img src="https://i.loli.net/2020/05/09/HXClIf5A2EpUG4u.png" width="240">
</p>

<p align="center">
<img alt="GitHub stars badge" src="https://img.shields.io/github/stars/cixingguangming55555/wechat-bot"> <img alt="GitHub forks badge" src="https://img.shields.io/github/forks/cixingguangming55555/wechat-bot"> <img alt="GitHub license badge" src="https://img.shields.io/github/license/cixingguangming55555/wechat-bot">

</p>

## 微信版本：3.9.2.23

## 新坑QQ群：712370539

## 如何使用

### 服务器端

第一步 启动PC微信并登陆完成，微信的版本必须是：3.9.2.23

第二步 启动非注入版，funtool.exe

第三步 点启动即可

### 客户端

本质就是构造一个json，当然，http和websocket的json构造，还有一些区别，具体请去看这两个文件：

websocket 客户端  ：client-3.2.1.121.js

http  客户端示例：http-3.2.1.121.js 

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

## API说明

### 1. 发送@消息 (send_at_msg)

- **URL**: **/api/sendatmsg**
- **Method**: POST
- **Description**: 发送@消息到指定的群聊中。
- **Payload**:
   - **id**: 请求唯一标识符
   - **type**: 消息类型 (AT_MSG)
   - **roomid**: 群聊ID
   - **wxid**: 用户微信ID
   - **content**: 消息内容
   - **nickname**: 用户昵称
   - **ext**: 扩展字段
### 2. 发送图片消息 (send_pic)

- **URL**: **/api/sendpic**
- **Method**: POST
- **Description**: 发送图片消息。
- **Payload**:
   - **id**: 请求唯一标识符
   - **type**: 消息类型 (PIC_MSG)
   - **wxid**: 用户或群ID
   - **roomid**: 群聊ID (如非群聊则为'null')
   - **content**: 图片文件路径
   - **nickname**: 用户昵称 (通常为'null')
   - **ext**: 扩展字段
### 3. 获取群成员昵称 (get_member_nick)

- **URL**: **/api/getmembernick**
- **Method**: POST
- **Description**: 获取指定群成员的昵称。
- **Payload**:
   - **id**: 请求唯一标识符
   - **type**: 请求类型 (CHATROOM_MEMBER_NICK)
   - **wxid**: 用户微信ID
   - **roomid**: 群聊ID
   - **content**: 通常为'null'
   - **nickname**: 用户昵称 (通常为'null')
   - **ext**: 扩展字段
### 4. 获取群成员ID列表 (get_memberid)

- **URL**: **/api/getmemberid**
- **Method**: POST
- **Description**: 获取指定群聊的所有成员ID。
- **Payload**:
   - **id**: 请求唯一标识符
   - **type**: 请求类型 (CHATROOM_MEMBER)
   - **wxid**: 用户或群ID (通常为'null')
   - **content**: 请求内容 (例如: 'op:list member')
### 5. 获取联系人和群列表 (get_contact_list)

- **URL**: **/api/getcontactlist**
- **Method**: POST
- **Description**: 获取联系人列表和群列表。
- **Payload**:
   - **id**: 请求唯一标识符
   - **type**: 请求类型 (USER_LIST)
   - **roomid**: 群聊ID (通常为'null')
   - **wxid**: 用户微信ID (通常为'null')
   - **content**: 通常为'null'
   - **nickname**: 用户昵称 (通常为'null')
   - **ext**: 扩展字段
### 6. 获取群聊成员列表 (get_chatroom_member_list)

- **URL**: **/api/get_charroom_member_list**
- **Method**: POST
- **Description**: 获取指定群聊的成员列表。
- **Payload**:
   - **id**: 请求唯一标识符
   - **type**: 请求类型 (CHATROOM_MEMBER)
   - **roomid**: 群聊ID
   - **wxid**: 用户微信ID
   - **content**: 通常为'null'
   - **nickname**: 用户昵称 (通常为'null')
   - **ext**: 扩展字段
### 7. 发送文本消息 (send_txt_msg)

- **URL**: **/api/sendtxtmsg**
- **Method**: POST
- **Description**: 发送文本消息。
- **Payload**:
   - **id**: 请求唯一标识符
   - **type**: 消息类型 (TXT_MSG)
   - **wxid**: 用户或群ID
   - **roomid**: 群聊ID (如非群聊则为'null')
   - **content**: 消息内容
   - **nickname**: 用户昵称 (通常为'null')
   - **ext**: 扩展字段
### 8. 发送附件 (send_attatch)

- **URL**: **/api/sendattatch**
- **Method**: POST
- **Description**: 发送文件作为附件。
- **Payload**:
   - **id**: 请求唯一标识符
   - **type**: 消息类型 (ATTATCH_FILE)
   - **wxid**: 用户或群ID
   - **roomid**: 群聊ID (如非群聊则为'null')
   - **content**: 文件路径
   - **nickname**: 用户昵称 (通常为'null')
   - **ext**: 扩展字段

## 多开请去此大佬处

https://github.com/crazyn2?tab=repositories

### 参考项目

* https://github.com/ChisBread/wechat-service
* 记得为这位大佬加星
