#pragma once
#include <QObject>
#include <vector>
#include <string>
#include <unordered_map>
#include "cJSON.h"

class WeChatBot;

enum ServerCode
{
	HEART_BEAT = 5005,
	RECV_TXT_MSG = 1,
	RECV_PIC_MSG = 3,
	USER_LIST = 5000,
	GET_USER_LIST_SUCCSESS = 5001,
	GET_USER_LIST_FAIL = 5002,
	TXT_MSG = 555,
	PIC_MSG = 500,
	AT_MSG = 550,
	CHATROOM_MEMBER = 5010,	//所有群聊成员列表
	CHATROOM_MEMBER_NICK = 5020,
	PERSONAL_INFO = 6500,
	DEBUG_SWITCH = 6000,
	PERSONAL_DETAIL = 6550,
	DESTROY_ALL = 9999,
	NEW_FRIEND_REQUEST = 37,//微信好友请求消息
	AGREE_TO_FRIEND_REQUEST = 10000,//同意微信好友请求消息
	ATTATCH_FILE = 5003,
};

class Logic : public QObject
{
	Q_OBJECT

signals:
	void update_wxuser_list(std::vector<cJSON *> items, std::vector<cJSON *> items2);
	void send_msg(std::string msg);
public:
	static Logic & Instance()
	{
		static Logic loc;
		return loc;
	}

	/**
	 * @brief 获得年月日时分秒的时间格式作为每次通信的id
	 * @param
	 * @return
	 */
	QString get_id();

	/**
	 * @brief 构造一条获取个人详细信息的消息
	 * @param
	 * @return
	 */
	QString get_personal_info();

	/**
	 * @brief 构造一条获得个人详细信息的消息
	 * @param wxid 要获得详细信息人的微信id
	 * @return
	 */
	QString  get_personal_detail(const char * wxid);

	/**
	 * @brief 构造一条获得通讯录列表的消息
	 * @param
	 * @return
	 */
	QString get_contact_list();

	/**
	 * @brief 构造一条发送文本消息的消息
	 * @param wxid 要发给谁
	 * @param content 要发什么
	 * @return
	 */
	QString send_txt_msg(const char * wxid, const char * content);

	/**
	 * @brief 构造一条发送文件消息的消息
	 * @param wxid 要发给谁
	 * @param img_path 要发送的文件路径
	 * @return
	 */
	QString send_pic_msg(const char * wxid, const char * img_path);

	/**
	 * @brief 构造一条在群内@别人消息的消息
	 * @param wxid 要@人的微信id
	 * @param rooid 群聊id
	 * @param content 消息内容
	 * @param nickname 要@的人的群昵称
	 * @return
	 */
	QString send_at_msg(const char * wxid, const char *  roomid, const char *  content, const char *  nickname);

	/**
	 * @brief 构造一条获得群成员昵称的消息, 此处测试结果为微信直接崩溃，不想探究
	 * @param wxid 该成员的wxid
	 * @param rooid 该成员所在群id
	 * @return
	 */
	QString get_chat_nick_p(const char * wxid, const char * roomid);

	/**
	 * @brief 构造一条获取群所有成员列表的消息
	 * @param
	 * @return
	 */
	QString get_chatroom_memberlist();

	/**
	 * @brief 处理文本消息
	 * @param
	 * @return
	 */
	void handle_txt_msg(cJSON * json);

	/**
	 * @brief 处理通讯录
	 * @param
	 * @return
	 */
	void handle_wxuser_list(cJSON * json);

	/**
	 * @brief 处理新好友或新成员
	 * @param
	 * @return
	 */
	void handle_new_member(cJSON * json);

	/**
	 * @brief 处理所有成员列表信息
	 * @param
	 * @return
	 */
	void handle_all_member_list(cJSON * json);

	/**
	 * @brief 根据消息调用对应的处理函数
	 * @param
	 * @return
	 */
	void dispatch_msg(cJSON * json);

	void set_instance(WeChatBot * ins)
	{
		instance_ = ins;
	}
private:
	Logic()
	{
	}

	//用于获取群聊和好友规则
	WeChatBot * instance_;

	//自己的wxid，对于获取个人信息和群昵称的接口一直有问题
	std::string my_wxid = "";

	//存储所有的群列表成员信息
	std::unordered_map<std::string,
		std::vector<std::unordered_map<std::string, std::string>>
	> all_chatroom_member_;
};
