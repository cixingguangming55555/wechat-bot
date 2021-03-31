package io.uouo.wechatbot.common;

/**
 * @author: [青衫] 'QSSSYH@QQ.com'
 * @Date: 2021-03-16 18:07
 * @Description: < 一些常量值 >
 */
public interface WechatBotCommon {

    /** 服务器返回心跳包 */
    int HEART_BEAT = 5005;
    /** 收到的消息为文字消息 */
    int RECV_TXT_MSG = 1;
    /** 收到的消息为图片消息 */
    int RECV_PIC_MSG = 3;
    // 微信好友请求消息
    int NEW_FRIEND_REQUEST = 37;
    /** 发送消息类型为文本 */
    int TXT_MSG = 555;
    /** 发送消息类型为图片 */
    int PIC_MSG = 500;
    /** 发送群中@用户的消息 */
    int AT_MSG = 550;

    /** 发送(接收) 消息类型为获取用户列表 */
    int USER_LIST = 5000;
    /** 获取用户列表成功响应状态码 */
    int GET_USER_LIST_SUCCSESS = 5001;
    /** 获取用户列表失败 */
    int GET_USER_LIST_FAIL = 5002;
    /** 附件消息 */
    int ATTATCH_FILE = 5003;
    /** 获取群成员 */
    int CHATROOM_MEMBER = 5010;
    /** 获取群成员详细信息 */
    int CHATROOM_MEMBER_NICK = 5020;
    int DEBUG_SWITCH = 6000;
    int PERSONAL_INFO = 6500;
    /** 获取指定联系人详细信息的 type */
    int PERSONAL_DETAIL = 6550;
    int DESTROY_ALL = 9999;

    // 同意微信好友请求消息
    int AGREE_TO_FRIEND_REQUEST = 10000;
    String ROOM_MEMBER_LIST = "op:list member";
    String CONTACT_LIST = "user list";
    String NULL_MSG = "null";


    String PERSONAL_DETAIL_CONTENT = "op:personal detail";


}
