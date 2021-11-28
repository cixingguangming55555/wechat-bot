#include "addreg.h"
#include <QTableWidget>
#include <QScrollBar>
#include <QPushButton>
#include <QMessageBox>
#include <QCheckBox>
#include <QDebug>
#include <QSettings>
#include <QDir>
#include <QTextCodec>
#include <iostream>
using namespace std;

void AddReg::on_reply_add_pushButton_clicked()
{
	QString reply = ui.reply_textEdit->toPlainText();
	if (reply.isEmpty() || reply == "")
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("回复内容不能为空"));
		return;
	}

	QString regex_str = ui.regex_textEdit->toPlainText();
	if (regex_str.isEmpty() || regex_str == "")
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("正则匹配不能为空"));
		return;
	}

	bool is_file_type = ui.reply_is_file_type_checkBox->isChecked();
	bool is_reply_at = ui.reply_is_at_checkBox->isChecked();
	int rowIndex = ui.tableWidget->rowCount();//当前表格的行数
	ui.tableWidget->insertRow(rowIndex);//在最后一行的后面插入一行
	ui.tableWidget->setItem(rowIndex, 0, new QTableWidgetItem(reply));
	ui.tableWidget->setItem(rowIndex, 1, new QTableWidgetItem(regex_str));
	auto c1 = new QCheckBox();
	c1->setChecked(is_file_type);
	ui.tableWidget->setCellWidget(rowIndex, 2, c1);
	auto c2 = new QCheckBox();
	c2->setChecked(is_reply_at);
	ui.tableWidget->setCellWidget(rowIndex, 3, c2);
}

void AddReg::on_reply_del_pushButton_clicked()
{
	int current_row_index = ui.tableWidget->currentRow();
	if (current_row_index == -1)
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("还未选中行"));
		return;
	}

	QMessageBox::StandardButton rb = QMessageBox::question(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("确定要删除吗"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	if (rb != QMessageBox::Yes)
	{
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		auto item = ui.tableWidget->item(current_row_index, i);
		delete item;
	}

	ui.tableWidget->removeRow(current_row_index);
}

void AddReg::on_new_member_add_pushButton_clicked()
{
	QString reply = ui.new_member_textEdit->toPlainText();
	if (reply.isEmpty() || reply == "")
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("回复内容不能为空"));
		return;
	}

	bool is_file_type = ui.new_member_is_file_type_checkBox->isChecked();
	bool is_reply_at = ui.new_member_is_at_checkBox->isChecked();
	int rowIndex = ui.new_member_tableWidget->rowCount();//当前表格的行数
	ui.new_member_tableWidget->insertRow(rowIndex);//在最后一行的后面插入一行
	ui.new_member_tableWidget->setItem(rowIndex, 0, new QTableWidgetItem(reply));
	auto c1 = new QCheckBox();
	c1->setChecked(is_file_type);
	ui.new_member_tableWidget->setCellWidget(rowIndex, 1, c1);
	auto c2 = new QCheckBox();
	c2->setChecked(is_reply_at);
	ui.new_member_tableWidget->setCellWidget(rowIndex, 2, c2);
}

void AddReg::on_new_member_del_pushButton_clicked()
{
	int current_row_index = ui.new_member_tableWidget->currentRow();
	if (current_row_index == -1)
	{
		QMessageBox::information(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("还未选中行"));
		return;
	}

	QMessageBox::StandardButton rb = QMessageBox::question(NULL, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("确定要删除吗"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	if (rb != QMessageBox::Yes)
	{
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		auto item = ui.new_member_tableWidget->item(current_row_index, i);
		delete item;
	}

	ui.new_member_tableWidget->removeRow(current_row_index);
}

void AddReg::on_sync_file_pushButton_clicked()
{
	QSettings iniFile(QDir::currentPath() + "/wechat.ini", QSettings::IniFormat);
	iniFile.setIniCodec(QTextCodec::codecForName("utf-8"));

	//保存该群聊回复规则
	int reply_count = ui.tableWidget->rowCount();
	do 
	{
		if (reply_count == 0)
			break;
		iniFile.beginGroup(editing_wxid_);
		iniFile.setValue("reg_count", reply_count);
		for (int i = 1; i <= reply_count; ++i)
		{
			iniFile.setValue(QString("reply") + QString::number(i), ui.tableWidget->item(i - 1, 0)->text());
			iniFile.setValue(QString("regex") + QString::number(i), ui.tableWidget->item(i - 1, 1)->text());
			QCheckBox * is_file = (QCheckBox*)(ui.tableWidget->cellWidget(i - 1, 2));
			iniFile.setValue(QString("is_file") + QString::number(i), is_file->isChecked());
			QCheckBox * is_at = (QCheckBox*)(ui.tableWidget->cellWidget(i - 1, 3));
			iniFile.setValue(QString("is_at") + QString::number(i), is_at->isChecked());
		}

		iniFile.endGroup();
	} while (0);

	//保存该群新成员回复内容
	int nm_reply_count = ui.new_member_tableWidget->rowCount();
	do
	{
		if (nm_reply_count == 0)
			break;
		iniFile.beginGroup(editing_wxid_ + "_nm");
		iniFile.setValue("reg_count", nm_reply_count);
		for (int i = 1; i <= nm_reply_count; ++i)
		{
			iniFile.setValue(QString("reply") + QString::number(i), ui.new_member_tableWidget->item(i - 1, 0)->text());
			QCheckBox * is_file = (QCheckBox*)(ui.new_member_tableWidget->cellWidget(i - 1, 1));
			iniFile.setValue(QString("is_file") + QString::number(i), is_file->isChecked());
			QCheckBox * is_at = (QCheckBox*)(ui.new_member_tableWidget->cellWidget(i - 1, 2));
			iniFile.setValue(QString("is_at") + QString::number(i), is_at->isChecked());
		}
		iniFile.endGroup();
	} while (0);

	emit reload_ini_file();
	QMessageBox::information(NULL, QString::fromLocal8Bit("信息"), QString::fromLocal8Bit("同步成功"));
}

AddReg::AddReg(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowModality(Qt::ApplicationModal);
	//设置水平方向隐藏滑动条
	ui.tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.new_member_tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	//设置头部栏每列均占满
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.new_member_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);
	setFixedSize(this->width(), this->height());

	mask_ = new Mask(this);
	mask_->move(width() / 2 - mask_->width() / 2, height() / 2 - mask_->height() / 2);
	hide_mask();

	load_init_timer_ = new QTimer(this);
	QObject::connect(load_init_timer_, SIGNAL(timeout()), this, SLOT(load_init_cb()));
}

AddReg::~AddReg()
{

}

void AddReg::load_init_cb()
{
	load_init_timer_->stop();
	QSettings iniFile(QDir::currentPath() + "/wechat.ini", QSettings::IniFormat);
	iniFile.setIniCodec(QTextCodec::codecForName("utf-8"));
	//此处有内存泄露的风险，但是是桌面程序且泄露极小，不处理
	ui.tableWidget->setRowCount(0);
	ui.new_member_tableWidget->setRowCount(0);
	//读取群聊回复规则
	iniFile.beginGroup(editing_wxid_);
	int reply_count = iniFile.value("reg_count", -1).toInt();
	do
	{
		if (reply_count <= 0)
		{
			break;
		}

		for (int i = 1; i <= reply_count; ++i)
		{
			QString reply = iniFile.value(QString("reply") + QString::number(i)).toString();
			QString regex = iniFile.value(QString("regex") + QString::number(i)).toString();
			bool is_file = iniFile.value(QString("is_file") + QString::number(i)).toBool();
			bool is_at = iniFile.value(QString("is_at") + QString::number(i)).toBool();

			//添加进列表
			int rowIndex = ui.tableWidget->rowCount();//当前表格的行数
			ui.tableWidget->insertRow(rowIndex);//在最后一行的后面插入一行
			ui.tableWidget->setItem(rowIndex, 0, new QTableWidgetItem(reply));
			ui.tableWidget->setItem(rowIndex, 1, new QTableWidgetItem(regex));
			auto c1 = new QCheckBox();
			c1->setChecked(is_file);
			ui.tableWidget->setCellWidget(rowIndex, 2, c1);
			auto c2 = new QCheckBox();
			c2->setChecked(is_at);
			ui.tableWidget->setCellWidget(rowIndex, 3, c2);
		}
	} while (0);
	iniFile.endGroup();

	//读取新成员入群回复规则
	iniFile.beginGroup(editing_wxid_ + "_nm");
	int nm_reply_count = iniFile.value("reg_count", -1).toInt();
	do
	{
		if (nm_reply_count <= 0)
		{
			break;
		}

		for (int i = 1; i <= nm_reply_count; ++i)
		{
			QString reply = iniFile.value(QString("reply") + QString::number(i)).toString();
			bool is_file = iniFile.value(QString("is_file") + QString::number(i)).toBool();
			bool is_at = iniFile.value(QString("is_at") + QString::number(i)).toBool();

			//添加进列表
			int rowIndex = ui.new_member_tableWidget->rowCount();//当前表格的行数
			ui.new_member_tableWidget->insertRow(rowIndex);//在最后一行的后面插入一行
			ui.new_member_tableWidget->setItem(rowIndex, 0, new QTableWidgetItem(reply));
			auto c1 = new QCheckBox();
			c1->setChecked(is_file);
			ui.new_member_tableWidget->setCellWidget(rowIndex, 1, c1);
			auto c2 = new QCheckBox();
			c2->setChecked(is_at);
			ui.new_member_tableWidget->setCellWidget(rowIndex, 2, c2);
		}
	} while (0);
	iniFile.endGroup();
	hide_mask();
}

void AddReg::show_mask()
{
	setEnabled(false);
	mask_->show();
}

void AddReg::hide_mask()
{
	setEnabled(true);
	mask_->hide();
}

void AddReg::delay_load()
{
	load_init_timer_->start(1000);
	show_mask();
}
