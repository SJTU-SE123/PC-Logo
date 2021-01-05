/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;
    QFontComboBox *fontComboBox;
    QComboBox *comboBox;
    QPushButton *sendButton;
    QPushButton *exitButton;

    void setupUi(QMainWindow *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(800, 480);
        centralwidget = new QWidget(Chat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 401, 261));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 300, 401, 151));
        fontComboBox = new QFontComboBox(centralwidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(20, 275, 213, 22));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(280, 275, 69, 22));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(70, 454, 75, 23));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(240, 454, 75, 23));
        Chat->setCentralWidget(centralwidget);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QMainWindow *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "\345\217\214\344\272\272\347\224\273\345\233\276", nullptr));
        comboBox->setItemText(0, QApplication::translate("Chat", "9", nullptr));
        comboBox->setItemText(1, QApplication::translate("Chat", "10", nullptr));
        comboBox->setItemText(2, QApplication::translate("Chat", "11", nullptr));
        comboBox->setItemText(3, QApplication::translate("Chat", "12", nullptr));
        comboBox->setItemText(4, QApplication::translate("Chat", "13", nullptr));
        comboBox->setItemText(5, QApplication::translate("Chat", "14", nullptr));
        comboBox->setItemText(6, QApplication::translate("Chat", "15", nullptr));
        comboBox->setItemText(7, QApplication::translate("Chat", "16", nullptr));
        comboBox->setItemText(8, QApplication::translate("Chat", "17", nullptr));

        sendButton->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
        exitButton->setText(QApplication::translate("Chat", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
