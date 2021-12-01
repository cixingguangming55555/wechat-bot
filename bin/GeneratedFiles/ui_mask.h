/********************************************************************************
** Form generated from reading UI file 'mask.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASK_H
#define UI_MASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mask
{
public:
    QLabel *label;

    void setupUi(QWidget *Mask)
    {
        if (Mask->objectName().isEmpty())
            Mask->setObjectName(QString::fromUtf8("Mask"));
        Mask->resize(400, 300);
        label = new QLabel(Mask);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 400, 300));
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        retranslateUi(Mask);

        QMetaObject::connectSlotsByName(Mask);
    } // setupUi

    void retranslateUi(QWidget *Mask)
    {
        Mask->setWindowTitle(QApplication::translate("Mask", "Mask", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Mask: public Ui_Mask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASK_H
