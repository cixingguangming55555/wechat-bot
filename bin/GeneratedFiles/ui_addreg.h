/********************************************************************************
** Form generated from reading UI file 'addreg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDREG_H
#define UI_ADDREG_H

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

class Ui_AddReg
{
public:
    QGroupBox *groupBox;
    QTableWidget *tableWidget;
    QPushButton *reply_add_pushButton;
    QPushButton *reply_del_pushButton;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *reply_is_file_type_checkBox;
    QCheckBox *reply_is_at_checkBox;
    QTextEdit *reply_textEdit;
    QTextEdit *regex_textEdit;
    QGroupBox *groupBox_2;
    QTableWidget *new_member_tableWidget;
    QPushButton *new_member_add_pushButton;
    QPushButton *new_member_del_pushButton;
    QLabel *label_7;
    QCheckBox *new_member_is_file_type_checkBox;
    QCheckBox *new_member_is_at_checkBox;
    QTextEdit *new_member_textEdit;
    QLabel *label_8;
    QPushButton *sync_file_pushButton;

    void setupUi(QWidget *AddReg)
    {
        if (AddReg->objectName().isEmpty())
            AddReg->setObjectName(QString::fromUtf8("AddReg"));
        AddReg->resize(729, 503);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddReg->sizePolicy().hasHeightForWidth());
        AddReg->setSizePolicy(sizePolicy);
        AddReg->setLayoutDirection(Qt::LeftToRight);
        AddReg->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(AddReg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 711, 231));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 20, 431, 201));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setTabletTracking(false);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        reply_add_pushButton = new QPushButton(groupBox);
        reply_add_pushButton->setObjectName(QString::fromUtf8("reply_add_pushButton"));
        reply_add_pushButton->setGeometry(QRect(450, 190, 121, 31));
        reply_del_pushButton = new QPushButton(groupBox);
        reply_del_pushButton->setObjectName(QString::fromUtf8("reply_del_pushButton"));
        reply_del_pushButton->setGeometry(QRect(580, 190, 121, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(450, 30, 54, 12));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(450, 100, 54, 12));
        reply_is_file_type_checkBox = new QCheckBox(groupBox);
        reply_is_file_type_checkBox->setObjectName(QString::fromUtf8("reply_is_file_type_checkBox"));
        reply_is_file_type_checkBox->setGeometry(QRect(452, 170, 111, 16));
        reply_is_at_checkBox = new QCheckBox(groupBox);
        reply_is_at_checkBox->setObjectName(QString::fromUtf8("reply_is_at_checkBox"));
        reply_is_at_checkBox->setGeometry(QRect(582, 170, 111, 16));
        reply_textEdit = new QTextEdit(groupBox);
        reply_textEdit->setObjectName(QString::fromUtf8("reply_textEdit"));
        reply_textEdit->setGeometry(QRect(450, 50, 251, 41));
        regex_textEdit = new QTextEdit(groupBox);
        regex_textEdit->setObjectName(QString::fromUtf8("regex_textEdit"));
        regex_textEdit->setGeometry(QRect(450, 120, 251, 41));
        groupBox_2 = new QGroupBox(AddReg);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 250, 721, 191));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        new_member_tableWidget = new QTableWidget(groupBox_2);
        if (new_member_tableWidget->columnCount() < 3)
            new_member_tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignCenter);
        new_member_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignCenter);
        new_member_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignCenter);
        new_member_tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        new_member_tableWidget->setObjectName(QString::fromUtf8("new_member_tableWidget"));
        new_member_tableWidget->setGeometry(QRect(10, 20, 431, 161));
        sizePolicy.setHeightForWidth(new_member_tableWidget->sizePolicy().hasHeightForWidth());
        new_member_tableWidget->setSizePolicy(sizePolicy);
        new_member_tableWidget->setTabletTracking(false);
        new_member_tableWidget->setAutoFillBackground(false);
        new_member_tableWidget->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        new_member_add_pushButton = new QPushButton(groupBox_2);
        new_member_add_pushButton->setObjectName(QString::fromUtf8("new_member_add_pushButton"));
        new_member_add_pushButton->setGeometry(QRect(450, 150, 121, 31));
        new_member_del_pushButton = new QPushButton(groupBox_2);
        new_member_del_pushButton->setObjectName(QString::fromUtf8("new_member_del_pushButton"));
        new_member_del_pushButton->setGeometry(QRect(590, 150, 121, 31));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(450, 30, 54, 12));
        new_member_is_file_type_checkBox = new QCheckBox(groupBox_2);
        new_member_is_file_type_checkBox->setObjectName(QString::fromUtf8("new_member_is_file_type_checkBox"));
        new_member_is_file_type_checkBox->setGeometry(QRect(452, 120, 111, 16));
        new_member_is_at_checkBox = new QCheckBox(groupBox_2);
        new_member_is_at_checkBox->setObjectName(QString::fromUtf8("new_member_is_at_checkBox"));
        new_member_is_at_checkBox->setGeometry(QRect(582, 120, 111, 16));
        new_member_textEdit = new QTextEdit(groupBox_2);
        new_member_textEdit->setObjectName(QString::fromUtf8("new_member_textEdit"));
        new_member_textEdit->setGeometry(QRect(450, 50, 261, 61));
        label_8 = new QLabel(AddReg);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(14, 450, 421, 41));
        label_8->setStyleSheet(QString::fromUtf8("font: italic 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        sync_file_pushButton = new QPushButton(AddReg);
        sync_file_pushButton->setObjectName(QString::fromUtf8("sync_file_pushButton"));
        sync_file_pushButton->setGeometry(QRect(460, 447, 261, 51));

        retranslateUi(AddReg);

        QMetaObject::connectSlotsByName(AddReg);
    } // setupUi

    void retranslateUi(QWidget *AddReg)
    {
        AddReg->setWindowTitle(QApplication::translate("AddReg", "\346\267\273\345\212\240\350\247\204\345\210\231", nullptr));
        groupBox->setTitle(QApplication::translate("AddReg", "\345\233\236\345\244\215\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AddReg", "\345\233\236\345\244\215\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AddReg", "\346\255\243\345\210\231\345\214\271\351\205\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AddReg", "\346\230\257\345\220\246\344\270\272\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AddReg", "\346\230\257\345\220\246@", nullptr));
        reply_add_pushButton->setText(QApplication::translate("AddReg", "\346\267\273\345\212\240\344\270\200\350\241\214\350\247\204\345\210\231", nullptr));
        reply_del_pushButton->setText(QApplication::translate("AddReg", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        label->setText(QApplication::translate("AddReg", "\345\233\236\345\244\215\345\206\205\345\256\271\357\274\232", nullptr));
        label_2->setText(QApplication::translate("AddReg", "\346\255\243\345\210\231\345\214\271\351\205\215\357\274\232", nullptr));
        reply_is_file_type_checkBox->setText(QApplication::translate("AddReg", "\346\230\257\345\220\246\344\270\272\346\226\207\344\273\266\347\261\273\345\236\213", nullptr));
        reply_is_at_checkBox->setText(QApplication::translate("AddReg", "\346\230\257\345\220\246@", nullptr));
        groupBox_2->setTitle(QApplication::translate("AddReg", "\346\226\260\346\210\220\345\221\230\345\233\236\345\244\215\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = new_member_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("AddReg", "\345\233\236\345\244\215\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = new_member_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("AddReg", "\346\230\257\345\220\246\344\270\272\346\226\207\344\273\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = new_member_tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("AddReg", "\346\230\257\345\220\246@", nullptr));
        new_member_add_pushButton->setText(QApplication::translate("AddReg", "\346\267\273\345\212\240\344\270\200\350\241\214\345\233\236\345\244\215", nullptr));
        new_member_del_pushButton->setText(QApplication::translate("AddReg", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        label_7->setText(QApplication::translate("AddReg", "\345\233\236\345\244\215\345\206\205\345\256\271\357\274\232", nullptr));
        new_member_is_file_type_checkBox->setText(QApplication::translate("AddReg", "\346\230\257\345\220\246\344\270\272\346\226\207\344\273\266\347\261\273\345\236\213", nullptr));
        new_member_is_at_checkBox->setText(QApplication::translate("AddReg", "\346\230\257\345\220\246@", nullptr));
        label_8->setText(QApplication::translate("AddReg", "\345\257\271\344\272\216\346\234\254\351\241\265\351\235\242\344\277\256\346\224\271\350\246\201\347\202\271\345\207\273\345\220\214\346\255\245\346\214\211\351\222\256\346\211\215\344\274\232\344\277\235\345\255\230\345\210\260\346\234\254\345\234\260", nullptr));
        sync_file_pushButton->setText(QApplication::translate("AddReg", "\345\220\214\346\255\245\346\234\254\351\241\265\351\235\242\346\211\200\346\234\211\350\247\204\345\210\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddReg: public Ui_AddReg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDREG_H
