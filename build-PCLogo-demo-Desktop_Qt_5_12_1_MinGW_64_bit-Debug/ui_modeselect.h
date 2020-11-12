/********************************************************************************
** Form generated from reading UI file 'modeselect.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODESELECT_H
#define UI_MODESELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModeSelect
{
public:
    QPushButton *LocalMode;
    QPushButton *NetMode;
    QPushButton *Tutorial;

    void setupUi(QWidget *ModeSelect)
    {
        if (ModeSelect->objectName().isEmpty())
            ModeSelect->setObjectName(QString::fromUtf8("ModeSelect"));
        ModeSelect->resize(500, 500);
        LocalMode = new QPushButton(ModeSelect);
        LocalMode->setObjectName(QString::fromUtf8("LocalMode"));
        LocalMode->setGeometry(QRect(145, 260, 210, 55));
        NetMode = new QPushButton(ModeSelect);
        NetMode->setObjectName(QString::fromUtf8("NetMode"));
        NetMode->setGeometry(QRect(145, 340, 210, 55));
        Tutorial = new QPushButton(ModeSelect);
        Tutorial->setObjectName(QString::fromUtf8("Tutorial"));
        Tutorial->setGeometry(QRect(145, 420, 210, 55));

        retranslateUi(ModeSelect);

        QMetaObject::connectSlotsByName(ModeSelect);
    } // setupUi

    void retranslateUi(QWidget *ModeSelect)
    {
        ModeSelect->setWindowTitle(QApplication::translate("ModeSelect", "Form", nullptr));
        LocalMode->setText(QString());
        NetMode->setText(QString());
        Tutorial->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ModeSelect: public Ui_ModeSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODESELECT_H
