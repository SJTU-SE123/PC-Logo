/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QPushButton *otherButton;
    QPushButton *Exit;
    QPushButton *ModeSelect;
    QPushButton *Help;

    void setupUi(QWidget *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(500, 500);
        otherButton = new QPushButton(StartWindow);
        otherButton->setObjectName(QString::fromUtf8("otherButton"));
        otherButton->setGeometry(QRect(470, 0, 31, 28));
        otherButton->setStyleSheet(QString::fromUtf8(""));
        Exit = new QPushButton(StartWindow);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(155, 420, 190, 50));
        ModeSelect = new QPushButton(StartWindow);
        ModeSelect->setObjectName(QString::fromUtf8("ModeSelect"));
        ModeSelect->setGeometry(QRect(155, 280, 190, 50));
        Help = new QPushButton(StartWindow);
        Help->setObjectName(QString::fromUtf8("Help"));
        Help->setGeometry(QRect(155, 350, 190, 50));

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QWidget *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "StartWindow", nullptr));
        otherButton->setText(QApplication::translate("StartWindow", "\342\200\246", nullptr));
        Exit->setText(QString());
        ModeSelect->setText(QString());
        Help->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
