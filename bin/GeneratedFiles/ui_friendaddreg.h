/********************************************************************************
** Form generated from reading UI file 'friendaddreg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDADDREG_H
#define UI_FRIENDADDREG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendAddReg
{
public:
    QGroupBox *groupBox;
    QTableWidget *tableWidget;
    QPushButton *reply_add_pushButton;
    QPushButton *reply_del_pushButton;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *reply_is_file_type_checkBox;
    QTextEdit *reply_textEdit;
    QTextEdit *regex_textEdit;
    QLabel *label_8;
    QPushButton *sync_file_pushButton;

    void setupUi(QWidget *FriendAddReg)
    {
        if (FriendAddReg->objectName().isEmpty())
            FriendAddReg->setObjectName(QString::fromUtf8("FriendAddReg"));
        FriendAddReg->resize(459, 444);
        groupBox = new QGroupBox(FriendAddReg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 451, 381));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 431, 201));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setTabletTracking(false);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        reply_add_pushButton = new QPushButton(groupBox);
        reply_add_pushButton->setObjectName(QString::fromUtf8("reply_add_pushButton"));
        reply_add_pushButton->setGeometry(QRect(310, 250, 121, 31));
        reply_del_pushButton = new QPushButton(groupBox);
        reply_del_pushButton->setObjectName(QString::fromUtf8("reply_del_pushButton"));
        reply_del_pushButton->setGeometry(QRect(310, 320, 121, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 220, 54, 12));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 290, 54, 12));
        reply_is_file_type_checkBox = new QCheckBox(groupBox);
        reply_is_file_type_checkBox->setObjectName(QString::fromUtf8("reply_is_file_type_checkBox"));
        reply_is_file_type_checkBox->setGeometry(QRect(12, 360, 111, 16));
        reply_textEdit = new QTextEdit(groupBox);
        reply_textEdit->setObjectName(QString::fromUtf8("reply_textEdit"));
        reply_textEdit->setGeometry(QRect(10, 240, 251, 41));
        regex_textEdit = new QTextEdit(groupBox);
        regex_textEdit->setObjectName(QString::fromUtf8("regex_textEdit"));
        regex_textEdit->setGeometry(QRect(10, 310, 251, 41));
        label_8 = new QLabel(FriendAddReg);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 390, 341, 41));
        label_8->setStyleSheet(QString::fromUtf8("font: italic 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        sync_file_pushButton = new QPushButton(FriendAddReg);
        sync_file_pushButton->setObjectName(QString::fromUtf8("sync_file_pushButton"));
        sync_file_pushButton->setGeometry(QRect(370, 390, 81, 51));

        retranslateUi(FriendAddReg);

        QMetaObject::connectSlotsByName(FriendAddReg);
    } // setupUi

    void retranslateUi(QWidget *FriendAddReg)
    {
        FriendAddReg->setWindowTitle(QApplication::translate("FriendAddReg", "FriendAddReg", nullptr));
        groupBox->setTitle(QApplication::translate("FriendAddReg", "\345\233\236\345\244\215\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FriendAddReg", "\345\233\236\345\244\215\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FriendAddReg", "\346\255\243\345\210\231\345\214\271\351\205\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FriendAddReg", "\346\230\257\345\220\246\344\270\272\346\226\207\344\273\266", nullptr));
        reply_add_pushButton->setText(QApplication::translate("FriendAddReg", "\346\267\273\345\212\240\344\270\200\350\241\214\350\247\204\345\210\231", nullptr));
        reply_del_pushButton->setText(QApplication::translate("FriendAddReg", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        label->setText(QApplication::translate("FriendAddReg", "\345\233\236\345\244\215\345\206\205\345\256\271\357\274\232", nullptr));
        label_2->setText(QApplication::translate("FriendAddReg", "\346\255\243\345\210\231\345\214\271\351\205\215\357\274\232", nullptr));
        reply_is_file_type_checkBox->setText(QApplication::translate("FriendAddReg", "\346\230\257\345\220\246\344\270\272\346\226\207\344\273\266\347\261\273\345\236\213", nullptr));
        label_8->setText(QApplication::translate("FriendAddReg", "\345\257\271\344\272\216\346\234\254\351\241\265\351\235\242\344\277\256\346\224\271\350\246\201\347\202\271\345\207\273\345\220\214\346\255\245\346\214\211\351\222\256\346\211\215\344\274\232\344\277\235\345\255\230\345\210\260\346\234\254\345\234\260", nullptr));
        sync_file_pushButton->setText(QApplication::translate("FriendAddReg", "\345\220\214\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendAddReg: public Ui_FriendAddReg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDADDREG_H
