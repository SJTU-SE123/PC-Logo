/********************************************************************************
** Form generated from reading UI file 'advancedchat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCEDCHAT_H
#define UI_ADVANCEDCHAT_H

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

class Ui_AdvancedChat
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QPushButton *exitButton;
    QPushButton *sendButton;
    QComboBox *comboBox;
    QFontComboBox *fontComboBox;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *AdvancedChat)
    {
        if (AdvancedChat->objectName().isEmpty())
            AdvancedChat->setObjectName(QString::fromUtf8("AdvancedChat"));
        AdvancedChat->resize(896, 626);
        centralwidget = new QWidget(AdvancedChat);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 30, 401, 261));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(260, 474, 75, 23));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(90, 474, 75, 23));
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
        comboBox->setGeometry(QRect(300, 295, 69, 22));
        fontComboBox = new QFontComboBox(centralwidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(40, 295, 213, 22));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 320, 401, 151));
        AdvancedChat->setCentralWidget(centralwidget);

        retranslateUi(AdvancedChat);

        QMetaObject::connectSlotsByName(AdvancedChat);
    } // setupUi

    void retranslateUi(QMainWindow *AdvancedChat)
    {
        AdvancedChat->setWindowTitle(QApplication::translate("AdvancedChat", "MainWindow", nullptr));
        exitButton->setText(QApplication::translate("AdvancedChat", "\351\200\200\345\207\272", nullptr));
        sendButton->setText(QApplication::translate("AdvancedChat", "\345\217\221\351\200\201", nullptr));
        comboBox->setItemText(0, QApplication::translate("AdvancedChat", "9", nullptr));
        comboBox->setItemText(1, QApplication::translate("AdvancedChat", "10", nullptr));
        comboBox->setItemText(2, QApplication::translate("AdvancedChat", "11", nullptr));
        comboBox->setItemText(3, QApplication::translate("AdvancedChat", "12", nullptr));
        comboBox->setItemText(4, QApplication::translate("AdvancedChat", "13", nullptr));
        comboBox->setItemText(5, QApplication::translate("AdvancedChat", "14", nullptr));
        comboBox->setItemText(6, QApplication::translate("AdvancedChat", "15", nullptr));
        comboBox->setItemText(7, QApplication::translate("AdvancedChat", "16", nullptr));
        comboBox->setItemText(8, QApplication::translate("AdvancedChat", "17", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AdvancedChat: public Ui_AdvancedChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCEDCHAT_H
