/********************************************************************************
** Form generated from reading UI file 'wechatbot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WECHATBOT_H
#define UI_WECHATBOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeChatBotClass
{
public:
    QWidget *back;
    QLabel *title;
    QPushButton *close_Button;
    QWidget *line;
    QPushButton *connect_Button;
    QWidget *container;
    QGroupBox *groupBox;
    QListWidget *friend_listWidget;
    QPushButton *edit_friend_Button;
    QGroupBox *groupBox_2;
    QListWidget *chatroom_listWidget;
    QPushButton *edit_chatroom_Button;
    QLineEdit *server_ip_edit;
    QListWidget *operator_list_Widget;
    QLabel *label;
    QSpinBox *server_port_box;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *log_textEdit;
    QPushButton *clear_op_Button;
    QPushButton *clear_log_Button;

    void setupUi(QWidget *WeChatBotClass)
    {
        if (WeChatBotClass->objectName().isEmpty())
            WeChatBotClass->setObjectName(QString::fromUtf8("WeChatBotClass"));
        WeChatBotClass->resize(1024, 768);
        WeChatBotClass->setContextMenuPolicy(Qt::NoContextMenu);
        WeChatBotClass->setStyleSheet(QString::fromUtf8("QPushButton:!hover\n"
"{ \n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(120, 120, 120, 255), stop:0.495 rgba(39, 39, 39, 255), stop:0.505 rgba(39,39, 39, 255), stop:1 rgba(120, 120,120, 255));\n"
"border: none;\n"
"border-radius:5px;\n"
"color: rgb(255, 255, 255);\n"
"font: 75 12pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"font: 75 10pt \"\351\273\221\344\275\223\";\n"
"}\n"
"\n"
"#back\n"
"{\n"
"border-radius:5px;\n"
"background-color: rgb(53, 53, 53);\n"
"}\n"
"\n"
"#closeButton{\n"
"font: 150 14pt \"\347\255\211\347\272\277\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(53, 53, 53);\n"
"}\n"
"\n"
"#title\n"
"{\n"
"color: rgb(0, 170, 255);\n"
"font: 75 12pt \"\351\273\221\344\275\223\";\n"
"}\n"
"#line\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(28, 28,28, 255), stop:1 rgba(68, 68, 68, 255));\n"
"}\n"
""));
        back = new QWidget(WeChatBotClass);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(0, 0, 1024, 768));
        title = new QLabel(back);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(30, 0, 691, 31));
        close_Button = new QPushButton(back);
        close_Button->setObjectName(QString::fromUtf8("close_Button"));
        close_Button->setGeometry(QRect(980, 10, 31, 16));
        line = new QWidget(back);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 1280, 2));
        connect_Button = new QPushButton(back);
        connect_Button->setObjectName(QString::fromUtf8("connect_Button"));
        connect_Button->setGeometry(QRect(940, 50, 71, 31));
        connect_Button->setContextMenuPolicy(Qt::NoContextMenu);
        container = new QWidget(back);
        container->setObjectName(QString::fromUtf8("container"));
        container->setGeometry(QRect(20, 51, 590, 690));
        container->setStyleSheet(QString::fromUtf8("#container\n"
"{\n"
"	background-color: white;\n"
"	border-radius: 5px;\n"
"}"));
        groupBox = new QGroupBox(container);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 571, 231));
        friend_listWidget = new QListWidget(groupBox);
        friend_listWidget->setObjectName(QString::fromUtf8("friend_listWidget"));
        friend_listWidget->setGeometry(QRect(20, 20, 391, 192));
        edit_friend_Button = new QPushButton(groupBox);
        edit_friend_Button->setObjectName(QString::fromUtf8("edit_friend_Button"));
        edit_friend_Button->setGeometry(QRect(440, 50, 111, 121));
        edit_friend_Button->setContextMenuPolicy(Qt::NoContextMenu);
        edit_friend_Button->setLayoutDirection(Qt::LeftToRight);
        edit_friend_Button->setAutoFillBackground(false);
        edit_friend_Button->setAutoRepeat(false);
        edit_friend_Button->setAutoDefault(false);
        groupBox_2 = new QGroupBox(container);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 240, 571, 231));
        chatroom_listWidget = new QListWidget(groupBox_2);
        chatroom_listWidget->setObjectName(QString::fromUtf8("chatroom_listWidget"));
        chatroom_listWidget->setGeometry(QRect(20, 20, 391, 192));
        edit_chatroom_Button = new QPushButton(groupBox_2);
        edit_chatroom_Button->setObjectName(QString::fromUtf8("edit_chatroom_Button"));
        edit_chatroom_Button->setGeometry(QRect(440, 50, 111, 121));
        edit_chatroom_Button->setContextMenuPolicy(Qt::NoContextMenu);
        edit_chatroom_Button->setLayoutDirection(Qt::LeftToRight);
        edit_chatroom_Button->setAutoFillBackground(false);
        edit_chatroom_Button->setAutoRepeat(false);
        edit_chatroom_Button->setAutoDefault(false);
        server_ip_edit = new QLineEdit(back);
        server_ip_edit->setObjectName(QString::fromUtf8("server_ip_edit"));
        server_ip_edit->setGeometry(QRect(700, 50, 121, 31));
        server_ip_edit->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        operator_list_Widget = new QListWidget(back);
        operator_list_Widget->setObjectName(QString::fromUtf8("operator_list_Widget"));
        operator_list_Widget->setGeometry(QRect(620, 150, 381, 291));
        operator_list_Widget->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;"));
        label = new QLabel(back);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(620, 50, 171, 21));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        server_port_box = new QSpinBox(back);
        server_port_box->setObjectName(QString::fromUtf8("server_port_box"));
        server_port_box->setGeometry(QRect(830, 50, 101, 31));
        server_port_box->setStyleSheet(QString::fromUtf8("font: 15pt \"ADMUI3Lg\";"));
        server_port_box->setMinimum(1);
        server_port_box->setMaximum(65535);
        server_port_box->setValue(5555);
        server_port_box->setDisplayIntegerBase(10);
        label_2 = new QLabel(back);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(620, 120, 171, 21));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(back);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(620, 450, 171, 21));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        log_textEdit = new QTextEdit(back);
        log_textEdit->setObjectName(QString::fromUtf8("log_textEdit"));
        log_textEdit->setGeometry(QRect(620, 480, 381, 261));
        log_textEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;"));
        clear_op_Button = new QPushButton(back);
        clear_op_Button->setObjectName(QString::fromUtf8("clear_op_Button"));
        clear_op_Button->setGeometry(QRect(930, 120, 71, 21));
        clear_op_Button->setContextMenuPolicy(Qt::NoContextMenu);
        clear_log_Button = new QPushButton(back);
        clear_log_Button->setObjectName(QString::fromUtf8("clear_log_Button"));
        clear_log_Button->setGeometry(QRect(930, 450, 71, 21));
        clear_log_Button->setContextMenuPolicy(Qt::NoContextMenu);

        retranslateUi(WeChatBotClass);

        QMetaObject::connectSlotsByName(WeChatBotClass);
    } // setupUi

    void retranslateUi(QWidget *WeChatBotClass)
    {
        WeChatBotClass->setWindowTitle(QApplication::translate("WeChatBotClass", "WeChatBot", nullptr));
        title->setText(QApplication::translate("WeChatBotClass", "\345\276\256\344\277\241\346\234\272\345\231\250\344\272\272v1.0", nullptr));
        close_Button->setText(QApplication::translate("WeChatBotClass", "X", nullptr));
        connect_Button->setText(QApplication::translate("WeChatBotClass", "\350\277\236\346\216\245", nullptr));
        groupBox->setTitle(QApplication::translate("WeChatBotClass", "\345\245\275\345\217\213", nullptr));
        edit_friend_Button->setText(QApplication::translate("WeChatBotClass", "\347\274\226\350\276\221\350\247\204\345\210\231", nullptr));
        groupBox_2->setTitle(QApplication::translate("WeChatBotClass", "\347\276\244\350\201\212", nullptr));
        edit_chatroom_Button->setText(QApplication::translate("WeChatBotClass", "\347\274\226\350\276\221\350\247\204\345\210\231", nullptr));
        server_ip_edit->setText(QApplication::translate("WeChatBotClass", "127.0.0.1", nullptr));
        label->setText(QApplication::translate("WeChatBotClass", "IP\345\222\214\347\253\257\345\217\243", nullptr));
        server_port_box->setSpecialValueText(QString());
        label_2->setText(QApplication::translate("WeChatBotClass", "\346\223\215\344\275\234\346\227\245\345\277\227", nullptr));
        label_3->setText(QApplication::translate("WeChatBotClass", "\346\224\266\345\210\260\346\225\260\346\215\256", nullptr));
        clear_op_Button->setText(QApplication::translate("WeChatBotClass", "\346\270\205\351\231\244", nullptr));
        clear_log_Button->setText(QApplication::translate("WeChatBotClass", "\346\270\205\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeChatBotClass: public Ui_WeChatBotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WECHATBOT_H
