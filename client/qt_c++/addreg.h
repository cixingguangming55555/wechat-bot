#pragma once

#include <QWidget>
#include <QTimer>
#include "ui_addreg.h"
#include "mask.h"

class AddReg : public QWidget
{
	Q_OBJECT

signals:
	void reload_ini_file();
public slots:
	/**
	 * @brief 添加一条匹配规则按钮点击事件
	 * @param
	 * @return
	 */
	void on_reply_add_pushButton_clicked();

	/**
	 * @brief 删除一条匹配规则按钮点击事件
	 * @param
	 * @return
	 */
	void on_reply_del_pushButton_clicked();

	/**
	 * @brief 添加一条新成员入群回复
	 * @param
	 * @return
	 */
	void on_new_member_add_pushButton_clicked();

	/**
	 * @brief 删除选中的新成员入群回复
	 * @param
	 * @return
	 */
	void on_new_member_del_pushButton_clicked();

	/**
	 * @brief 同步本页面数据按钮点击事件
	 * @param
	 * @return
	 */
	void on_sync_file_pushButton_clicked();

	/**
	 * @brief 初始化本页面，主要为读取配置文件中的所有规则
	 * @param
	 * @return
	 */
	void load_init_cb();
public:
	AddReg(QWidget *parent = Q_NULLPTR);
	~AddReg();

	void show_mask();
	void hide_mask();

	void set_wxid(QString & id)
	{
		editing_wxid_ = id;
	}

	void delay_load();
private:
	//当前正在编辑的wxid
	QString editing_wxid_;
	//mask指针
	Mask * mask_ = nullptr;
	//延迟加载配置文件的定时器
	QTimer * load_init_timer_ = nullptr;
	Ui::AddReg ui;
};
