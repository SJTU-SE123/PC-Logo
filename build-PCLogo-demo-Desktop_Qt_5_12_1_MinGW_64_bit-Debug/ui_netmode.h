/********************************************************************************
** Form generated from reading UI file 'netmode.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETMODE_H
#define UI_NETMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetMode
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NetMode)
    {
        if (NetMode->objectName().isEmpty())
            NetMode->setObjectName(QString::fromUtf8("NetMode"));
        NetMode->resize(359, 428);
        centralwidget = new QWidget(NetMode);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 600, 450));
        tableWidget->horizontalHeader()->setDefaultSectionSize(120);
        NetMode->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(NetMode);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NetMode->setStatusBar(statusbar);

        retranslateUi(NetMode);

        QMetaObject::connectSlotsByName(NetMode);
    } // setupUi

    void retranslateUi(QMainWindow *NetMode)
    {
        NetMode->setWindowTitle(QApplication::translate("NetMode", "\345\217\214\345\207\273\351\200\211\346\213\251\344\274\231\344\274\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("NetMode", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("NetMode", "\347\212\266\346\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetMode: public Ui_NetMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETMODE_H
