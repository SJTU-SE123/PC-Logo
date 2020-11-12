/********************************************************************************
** Form generated from reading UI file 'localmode.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALMODE_H
#define UI_LOCALMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocalMode
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *action_9;
    QAction *action_11;
    QAction *action_12;
    QAction *action_13;
    QAction *action_14;
    QAction *action_15;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LocalMode)
    {
        if (LocalMode->objectName().isEmpty())
            LocalMode->setObjectName(QString::fromUtf8("LocalMode"));
        LocalMode->resize(1200, 800);
        action = new QAction(LocalMode);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(LocalMode);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(LocalMode);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(LocalMode);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(LocalMode);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_6 = new QAction(LocalMode);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        action_7 = new QAction(LocalMode);
        action_7->setObjectName(QString::fromUtf8("action_7"));
        action_8 = new QAction(LocalMode);
        action_8->setObjectName(QString::fromUtf8("action_8"));
        action_9 = new QAction(LocalMode);
        action_9->setObjectName(QString::fromUtf8("action_9"));
        action_11 = new QAction(LocalMode);
        action_11->setObjectName(QString::fromUtf8("action_11"));
        action_12 = new QAction(LocalMode);
        action_12->setObjectName(QString::fromUtf8("action_12"));
        action_13 = new QAction(LocalMode);
        action_13->setObjectName(QString::fromUtf8("action_13"));
        action_14 = new QAction(LocalMode);
        action_14->setObjectName(QString::fromUtf8("action_14"));
        action_15 = new QAction(LocalMode);
        action_15->setObjectName(QString::fromUtf8("action_15"));
        centralwidget = new QWidget(LocalMode);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LocalMode->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LocalMode);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        LocalMode->setMenuBar(menubar);
        statusbar = new QStatusBar(LocalMode);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LocalMode->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu->addAction(action_3);
        menu->addAction(action_4);
        menu->addAction(action_5);
        menu->addSeparator();
        menu->addAction(action_11);
        menu_2->addAction(action_6);
        menu_2->addAction(action_7);
        menu_2->addAction(action_8);
        menu_3->addAction(action_9);
        menu_4->addAction(action_12);
        menu_4->addAction(action_13);
        menu_4->addAction(action_14);
        menu_4->addAction(action_15);

        retranslateUi(LocalMode);

        QMetaObject::connectSlotsByName(LocalMode);
    } // setupUi

    void retranslateUi(QMainWindow *LocalMode)
    {
        LocalMode->setWindowTitle(QApplication::translate("LocalMode", "MainWindow", nullptr));
        action->setText(QApplication::translate("LocalMode", "\346\226\260\345\273\272", nullptr));
        action_2->setText(QApplication::translate("LocalMode", "\346\211\223\345\274\200", nullptr));
        action_3->setText(QApplication::translate("LocalMode", "\344\277\235\345\255\230", nullptr));
        action_4->setText(QApplication::translate("LocalMode", "\345\217\246\345\255\230\344\270\272", nullptr));
        action_5->setText(QApplication::translate("LocalMode", "\351\200\200\345\207\272", nullptr));
        action_6->setText(QApplication::translate("LocalMode", "\345\244\215\345\210\266", nullptr));
        action_7->setText(QApplication::translate("LocalMode", "\345\211\252\345\210\207", nullptr));
        action_8->setText(QApplication::translate("LocalMode", "\347\262\230\350\264\264", nullptr));
        action_9->setText(QApplication::translate("LocalMode", "\345\270\256\345\212\251\346\226\207\346\241\243", nullptr));
        action_11->setText(QApplication::translate("LocalMode", "\344\270\212\344\274\240\350\207\263\347\244\276\345\214\272", nullptr));
        action_12->setText(QApplication::translate("LocalMode", "\350\277\220\350\241\214", nullptr));
        action_13->setText(QApplication::translate("LocalMode", "\345\255\220\347\250\213\345\272\217\350\241\250", nullptr));
        action_14->setText(QApplication::translate("LocalMode", "\350\260\203\350\257\225", nullptr));
        action_15->setText(QApplication::translate("LocalMode", "\346\236\204\345\273\272", nullptr));
        menu->setTitle(QApplication::translate("LocalMode", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("LocalMode", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QApplication::translate("LocalMode", "\345\270\256\345\212\251", nullptr));
        menu_4->setTitle(QApplication::translate("LocalMode", "\347\250\213\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LocalMode: public Ui_LocalMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALMODE_H
