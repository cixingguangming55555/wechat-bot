#include "logic.h"
#include "cJSON.h"
#include "wechatbot.h"
#include "tools.h"
#include <QDateTime>
#include <string>
#include <QMessageBox>
#include <regex>
#include <QDebug>
#include <vector>
#include <iostream>
using namespace std;

QString Logic::get_id()
{
	return QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
}

QString Logic::get_personal_info()
{
	cJSON * json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "id", get_id().toStdString().c_str());
	cJSON_AddNumberToObject(json, "type", PERSONAL_INFO);
	cJSON_AddStringToObject(json, "wxid", "null");
	cJSON_AddStringToObject(json, "roomid", "null");
	cJSON_AddStringToObject(json, "content", "null");
	cJSON_AddStringToObject(json, "nickname", "null");
	cJSON_AddStringToObject(json, "ext", "null");
	char * is_need_free_str = cJSON_Print(json);
	cJSON_Delete(json);
	QString re(is_need_free_str);
	free(is_need_free_str);
	return re;
}

QString Logic::get_personal_detail(const char * wxid)
{
	cJSON * json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "id", get_id().toStdString().c_str());
	cJSON_AddNumberToObject(json, "type", PERSONAL_DETAIL);
	cJSON_AddStringToObject(json, "content", "op:personal detail");
	cJSON_AddStringToObject(json, "wxid", wxid);
	char * is_need_free_str = cJSON_Print(json);
	cJSON_Delete(json);
	QString re(is_need_free_str);
	free(is_need_free_str);
	return re;
}

QString Logic::get_contact_list()
{
	cJSON * json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "id", get_id().toStdString().c_str());
	cJSON_AddNumberToObject(json, "type", USER_LIST);
	cJSON_AddStringToObject(json, "wxid", "null");
	cJSON_AddStringToObject(json, "roomid", "null");
	cJSON_AddStringToObject(json, "content", "null");
	cJSON_AddStringToObject(json, "nickname", "null");
	cJSON_AddStringToObject(json, "ext", "null");
	char * is_need_free_str = cJSON_Print(json);
	cJSON_Delete(json);
	QString re(is_need_free_str);
	free(is_need_free_str);
	return re;
}

QString Logic::send_txt_msg(const char * wxid, const char * content)
{
	cJSON * json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "id", get_id().toStdString().c_str());
	cJSON_AddNumberToObject(json, "type", TXT_MSG);
	cJSON_AddStringToObject(json, "wxid", wxid);
	cJSON_AddStringToObject(json, "roomid", "null");
	cJSON_AddStringToObject(json, "content", content);
	cJSON_AddStringToObject(json, "nickname", "null");
	cJSON_AddStringToObject(json, "ext", "null");
	char * is_need_free_str = cJSON_Print(json);
	cJSON_Delete(json);
	QString re(is_need_free_str);
	free(is_need_free_str);
	return re;
}

QString Logic::send_pic_msg(const char * wxid, const char * img_path)
{
	cJSON * json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "id", get_id().toStdString().c_str());
	cJSON_AddNumberToObject(json, "type", PIC_MSG);
	cJSON_AddStringToObject(json, "wxid", wxid);
	cJSON_AddStringToObject(json, "roomid", "null");
	cJSON_AddStringToObject(json, "content", img_path);
	cJSON_AddStringToObject(json, "nickname", "null");
	cJSON_AddStringToObject(json, "ext", "null");
	char * is_need_free_str = cJSON_Print(json);
	cJSON_Delete(json);
	QString re(is_need_free_str);
	free(is_need_free_str);
	return re;
}

QString Logic::send_at_msg(const char * wxid, const char * roomid, const char * content, const char * nickname)
{
	cJSON * json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "id", get_id().toStdString().c_str());
	cJSON_AddNumberToObject(json, "type", AT_MSG);
	cJSON_AddStringToObject(json, "wxid", wxid);
	cJSON_AddStringToObject(json, "roomid", roomid);
	cJSON_AddStringToObject(json, "content", content);
	cJSON_AddStringToObject(json, "nickname", nickname);
	cJSON_AddStringToObject(json, "ext", "null");
	char * is_need_free_str = cJSON_Print(json);
	cJSON_Delete(json);
	QString re(is_need_free_str);
	free(is_need_free_str);
	return re;
}

QString Logic::get_chat_nick_p(const char * wxid, const char * roomid)
{
	cJSON * json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "id", get_id().toStdString().c_str());
	cJSON_AddNumberToObject(json, "type", CHATROOM_MEMBER_NICK);
	cJSON_AddStringToObject(json, "wxid", wxid);
	cJSON_AddStringToObject(json, "roomid", roomid);
	cJSON_AddStringToObject(json, "content", "null");
	cJSON_AddStringToObject(json, "nickname", "null");
	cJSON_AddStringToObject(json, "ext", "null");
	char * is_need_free_str = cJSON_Print(json);
	cJSON_Delete(json);
	QString re(is_need_free_str);
	free(is_need_free_str);
	return re;
}

QString Logic::get_chatroom_memberlist()
{
	cJSON * json = cJSON_CreateObject();
	cJSON_AddStringToObject(json, "id", get_id().toStdString().c_str());
	cJSON_AddNumberToObject(json, "type", CHATROOM_MEMBER);
	cJSON_AddStringToObject(json, "wxid", "null");
	cJSON_AddStringToObject(json, "roomid", "null");
	cJSON_AddStringToObject(json, "content", "null");
	cJSON_AddStringToObject(json, "nickname", "null");
	cJSON_AddStringToObject(json, "exts", "null");
	char * is_need_free_str = cJSON_Print(json);
	cJSON_Delete(json);
	QString re(is_need_free_str);
	free(is_need_free_str);
	return re;
}

void Logic::handle_wxuser_list(cJSON * json)
{
	cJSON * content = cJSON_GetObjectItem(json, "content");
	int arr_size = cJSON_GetArraySize(content);
	cJSON * item;
	vector<cJSON*> friends;
	vector<cJSON*> chatrooms;
	for (int i = 0; i < arr_size; ++i)
	{
		item = cJSON_GetArrayItem(content, i);
		cJSON * val = cJSON_GetObjectItem(item, "wxid");
		if (!val)
			continue;
		QString wxid = val->valuestring;
		if (wxid.startsWith("wxid"))
		{//是微信好友
			//qDebug() << "friend: " << cJSON_GetObjectItem(item, "name")->valuestring;
			friends.push_back(item);
		}
		else if (wxid.endsWith("@chatroom"))
		{//是群聊
			//qDebug() << "chatroom: " << cJSON_GetObjectItem(item, "name")->valuestring;
			chatrooms.push_back(item);
		}
		else if (wxid.startsWith("gh"))
		{//公众号
			//qDebug() << "ps: " << cJSON_GetObjectItem(item, "name")->valuestring;
		}
		else
		{//其他一律不管
		}
	}

	emit update_wxuser_list(friends, chatrooms);
}

void Logic::handle_new_member(cJSON * json)
{
	cJSON * content = cJSON_GetObjectItem(json, "content");
	std::regex pattern(".*?邀请\"(.*?)\"加入了群聊");
	string text = UTF8ToGBK(cJSON_GetObjectItem(content, "content")->valuestring);
	string wxid = cJSON_GetObjectItem(content, "id1")->valuestring;
	smatch results;
	if (!regex_search(text, results, pattern))
		return;

	string nickname = GBKToUTF8(results[1].str().c_str());
	auto all_regs_iter = instance_->all_chatoom_regs_.find(wxid + "_nm");
	if (all_regs_iter == instance_->all_chatoom_regs_.end())
	{//理论上不可能发生
		QMessageBox::information(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("程序出现异常，请重启"));
		return;
	}
	for (auto & reg : all_regs_iter->second)
	{
		string reply = reg.find("reply")->second;
		bool is_at = reg.find("is_at")->second == "1" ? true : false;
		bool is_file = reg.find("is_file")->second == "1" ? true : false;
		if (is_at)
		{
			if (is_file)
			{
				instance_->send_msg(send_at_msg(my_wxid.c_str(), wxid.c_str(), "", nickname.c_str()).toStdString());
				instance_->send_msg(send_pic_msg(wxid.c_str(), reply.c_str()).toStdString());
			}
			else
			{
				instance_->send_msg(send_at_msg(my_wxid.c_str(), wxid.c_str(), reply.c_str(), nickname.c_str()).toStdString());
			}
		}
		else
		{
			if (is_file)
			{
				instance_->send_msg(send_pic_msg(wxid.c_str(), reply.c_str()).toStdString());
			}
			else
			{
				instance_->send_msg(send_txt_msg(wxid.c_str(), reply.c_str()).toStdString());
			}
		}
	}
}

void Logic::handle_all_member_list(cJSON * json)
{
	cJSON * content = cJSON_GetObjectItem(json, "content");
	int count = cJSON_GetArraySize(content);
	for (int i = 0; i < count; ++i)
	{
		cJSON * item = cJSON_GetArrayItem(content, i);
		string roomid = cJSON_GetObjectItem(item, "room_id")->valuestring;
		cJSON * member_list = cJSON_GetObjectItem(item, "member");
		int member_list_count = cJSON_GetArraySize(member_list);
		vector<unordered_map<string, string>> all_one_item;
		for (int j = 0; j < member_list_count; ++j)
		{
			cJSON * mem_item = cJSON_GetArrayItem(member_list, j);
			unordered_map<string, string> one_item;
			one_item[mem_item->valuestring] = "";
			all_one_item.push_back(one_item);
		}

		all_chatroom_member_[roomid] = all_one_item;
	}
}

void Logic::handle_txt_msg(cJSON * json)
{
	cJSON * content = cJSON_GetObjectItem(json, "content");
	string wxid = cJSON_GetObjectItem(json, "wxid")->valuestring;
	regex reg("\\d{11}@chatroom");
	if (regex_match(wxid, reg))
	{//是群聊
		auto all_regs_iter = instance_->all_chatoom_regs_.find(wxid);
		if (all_regs_iter == instance_->all_chatoom_regs_.end())
		{//理论上不可能发生
			QMessageBox::information(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("程序出现异常，请重启"));
			return;
		}
		for (auto & reg : all_regs_iter->second)
		{
			string regex_str = reg.find("regex")->second;
			if (regex_match(content->valuestring, std::regex(regex_str)))
			{//匹配到了
				string reply = reg.find("reply")->second;
				bool is_file = reg.find("is_file")->second == "1" ? true : false;
				bool is_at = reg.find("is_at")->second == "1" ? true : false;

				if (is_at)
				{
					const char * id1 = cJSON_GetObjectItem(json, "id1")->valuestring;
					if (is_file)
					{
						instance_->send_msg(send_at_msg(id1, wxid.c_str(), "", "").toStdString());
						instance_->send_msg(send_pic_msg(wxid.c_str(), reply.c_str()).toStdString());
					}
					else
					{
						instance_->send_msg(send_at_msg(id1, wxid.c_str(), reply.c_str(), "").toStdString());
					}
				}
				else
				{
					if (is_file)
					{
						instance_->send_msg(send_pic_msg(wxid.c_str(), reply.c_str()).toStdString());
					}
					else
					{
						instance_->send_msg(send_txt_msg(wxid.c_str(), reply.c_str()).toStdString());
					}
				}
			}
		}
	}
	else
	{//是私聊
		my_wxid = wxid;
		auto all_regs_iter = instance_->all_friend_regs_.find(wxid);
		if (all_regs_iter == instance_->all_friend_regs_.end())
		{//理论上不可能发生
			QMessageBox::information(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("程序出现异常，请重启"));
			return;
		}
		for (auto & reg : all_regs_iter->second)
		{
			string regex_str = reg.find("regex")->second;
			if (regex_match(content->valuestring, std::regex(regex_str)))
			{//匹配到了
				string reply = reg.find("reply")->second;
				bool is_file = reg.find("is_file")->second == "1" ? true : false;
				const char * id1 = cJSON_GetObjectItem(json, "id1")->valuestring;
				if (is_file)
				{
					instance_->send_msg(send_pic_msg(wxid.c_str(), reply.c_str()).toStdString());
				}
				else
				{
					instance_->send_msg(send_txt_msg(wxid.c_str(), reply.c_str()).toStdString());
				}
			}
		}
	}
}

void Logic::dispatch_msg(cJSON * json)
{
	int type = cJSON_GetObjectItem(json, "type")->valueint;
	/*char * is_need_free_str = cJSON_Print(json);
	qDebug() << is_need_free_str;
	free(is_need_free_str);*/
	switch (type)
	{
	case PERSONAL_INFO:
		break;
	case RECV_TXT_MSG:
		handle_txt_msg(json);
		break;
	case USER_LIST:
		handle_wxuser_list(json);
		break;
	case AGREE_TO_FRIEND_REQUEST:	//新好友或新群友
		handle_new_member(json);
		break;
	case CHATROOM_MEMBER:
		handle_all_member_list(json);
		break;
	default:
		break;
	}
}
