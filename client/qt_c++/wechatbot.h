#pragma once

#include <QtWidgets/QWidget>
#include <QWebSocket>
#include <string>
#include <unordered_map>
#include <vector>
#include <string>
#include <QTimer>
#include "ui_wechatbot.h"
#include "addreg.h"
#include "friendaddreg.h"
#include "mask.h"

struct cJSON;

class WeChatBot : public QWidget
{
	Q_OBJECT

public:
	WeChatBot(QWidget *parent = Q_NULLPTR);

	void mouseMoveEvent(QMouseEvent *ev) override;

	void mousePressEvent(QMouseEvent *ev) override;

	void mouseReleaseEvent(QMouseEvent *ev) override;

	/**
	 * @brief 添加到操作日志
	 * @param log 日志消息
	 * @return
	 */
	void show_log(const QString & log);

	/**
	 * @brief 将收到的json数据显示在数据框内
	 * @param data 从微信发来的数据
	 * @return
	 */
	void show_data(const QString & data);

	/**
	 * @brief 给微信服务端发送消息
	 * @param
	 * @return
	 */
	void send_msg(const char * msg);
	void send_msg(std::string & msg);
	void send_msg(QString & msg);
	
public slots:

	/**
	 * @brief 点击右上角x按钮关闭整个qt程序
	 * @param
	 * @return
	 */
	void on_close_Button_clicked();

	/**
	 * @brief 清除操作日志点击事件
	 * @param
	 * @return
	 */
	void on_clear_op_Button_clicked();

	/**
	 * @brief 清除数据日志点击事件
	 * @param
	 * @return
	 */
	void on_clear_log_Button_clicked();

	/**
	 * @brief 点击连接按钮事件
	 * @param
	 * @return
	 */
	void on_connect_Button_clicked();

	/**
	 * @brief ws客户端连接成功回调
	 * @param
	 * @return
	 */
	void ws_client_connected_cb();

	/**
	 * @brief ws客户端收到数据回调
	 * @param msg 收到的数据
	 * @return
	 */
	void ws_client_received_cb(const QString & msg);

	/**
	 * @brief 当ws客户端断开连接时的回调函数
	 * @param
	 * @return
	 */
	void ws_client_disconnected_cb();

	/**
	 * @brief 点击编辑好友回复规则事件
	 * @param
	 * @return
	 */
	void on_edit_friend_Button_clicked();

	/**
	 * @brief 点击编辑群聊回复规则事件
	 * @param
	 * @return
	 */
	void on_edit_chatroom_Button_clicked();

	/**
	 * @brief 更新好友和群聊列表
	 * @param item 好友json数据队列
	 * @param item2 群聊json数据队列
	 * @return
	 */
	void update_wxuser_list(std::vector<cJSON *> items, std::vector<cJSON *> items2);

	/**
	 * @brief 打开加载动画
	 * @param
	 * @return
	 */
	void show_mask();

	/**
	 * @brief 关闭加载动画
	 * @param
	 * @return
	 */
	void hide_mask();

	/**
	 * @brief 将所有回复的规则重新加载入内存
	 * @param
	 * @return
	 */
	void reload_ini_file();

	/**
	 * @brief 将所有好友回复的规则重新加载入内存
	 * @param
	 * @return
	 */
	void reload_f_ini_file();

	/**
	 * @brief 获取wxuser超时回调函数
	 * @param
	 * @return
	 */
	void get_wxuser_timer_slot();

private:
	Ui::WeChatBotClass ui;

	//与微信通信的ws客户端
	QWebSocket * ws_client_ = nullptr;

	//表示ws客户端是否正常连接至服务端
	bool is_ws_client_connected_ = false;

	//本次连接服务端的ip和端口
	QString server_ip_ = "";
	int server_port_ = -1;

	//存放所有的群聊信息
	std::unordered_map<std::string, std::string> all_chatroom_;

	//存放所有的好友信息
	std::unordered_map<std::string, std::string> all_friend_;

public:
	//存放所有的群聊规则
	std::unordered_map<std::string,
		std::vector<std::unordered_map<std::string, 
					std::string>
		>
	> all_chatoom_regs_;
	//存放所有的好友规则
	std::unordered_map<std::string,
		std::vector<std::unordered_map<std::string, 
					std::string>
		>
	> all_friend_regs_;
private:
	//mask指针
	Mask * mask_ = nullptr;

	//addReg指针
	AddReg * add_reg_ = nullptr;

	//friend添加规则界面指针
	FriendAddReg * f_add_reg_ = nullptr;

	//点击连接后会获取通讯录信息，点击后开启mask，刷新信息后关闭mask的超时定时器
	QTimer * get_wxuser_timer_ = nullptr;
};
