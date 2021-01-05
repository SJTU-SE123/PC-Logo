/********************************************************************************
** Form generated from reading UI file 'connect.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_H
#define UI_CONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connect
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QListView *listView;
    QPushButton *pushButton;

    void setupUi(QWidget *Connect)
    {
        if (Connect->objectName().isEmpty())
            Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->resize(400, 300);
        label = new QLabel(Connect);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 91, 16));
        lineEdit = new QLineEdit(Connect);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 30, 150, 21));
        listView = new QListView(Connect);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(60, 60, 256, 192));
        pushButton = new QPushButton(Connect);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 260, 93, 28));

        retranslateUi(Connect);

        QMetaObject::connectSlotsByName(Connect);
    } // setupUi

    void retranslateUi(QWidget *Connect)
    {
        Connect->setWindowTitle(QApplication::translate("Connect", "Form", nullptr));
        label->setText(QApplication::translate("Connect", "\346\237\245\346\211\276\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("Connect", "\347\241\256\350\256\244\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Connect: public Ui_Connect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_H
