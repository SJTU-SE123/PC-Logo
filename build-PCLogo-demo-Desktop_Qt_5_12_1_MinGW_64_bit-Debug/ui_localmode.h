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
    QAction *action_new;
    QAction *action_open;
    QAction *action_save;
    QAction *action_save_as;
    QAction *action_exit;
    QAction *action_copy;
    QAction *action_cut;
    QAction *action_paste;
    QAction *action_help;
    QAction *action_upload;
    QAction *action_run;
    QAction *action_procedures;
    QAction *action_debug;
    QAction *action_build;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_edit;
    QMenu *menu_help;
    QMenu *menu_program;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LocalMode)
    {
        if (LocalMode->objectName().isEmpty())
            LocalMode->setObjectName(QString::fromUtf8("LocalMode"));
        LocalMode->resize(1200, 800);
        action_new = new QAction(LocalMode);
        action_new->setObjectName(QString::fromUtf8("action_new"));
        action_open = new QAction(LocalMode);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        action_save = new QAction(LocalMode);
        action_save->setObjectName(QString::fromUtf8("action_save"));
        action_save_as = new QAction(LocalMode);
        action_save_as->setObjectName(QString::fromUtf8("action_save_as"));
        action_exit = new QAction(LocalMode);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_copy = new QAction(LocalMode);
        action_copy->setObjectName(QString::fromUtf8("action_copy"));
        action_cut = new QAction(LocalMode);
        action_cut->setObjectName(QString::fromUtf8("action_cut"));
        action_paste = new QAction(LocalMode);
        action_paste->setObjectName(QString::fromUtf8("action_paste"));
        action_help = new QAction(LocalMode);
        action_help->setObjectName(QString::fromUtf8("action_help"));
        action_upload = new QAction(LocalMode);
        action_upload->setObjectName(QString::fromUtf8("action_upload"));
        action_run = new QAction(LocalMode);
        action_run->setObjectName(QString::fromUtf8("action_run"));
        action_procedures = new QAction(LocalMode);
        action_procedures->setObjectName(QString::fromUtf8("action_procedures"));
        action_debug = new QAction(LocalMode);
        action_debug->setObjectName(QString::fromUtf8("action_debug"));
        action_build = new QAction(LocalMode);
        action_build->setObjectName(QString::fromUtf8("action_build"));
        centralwidget = new QWidget(LocalMode);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LocalMode->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LocalMode);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 26));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_edit = new QMenu(menubar);
        menu_edit->setObjectName(QString::fromUtf8("menu_edit"));
        menu_help = new QMenu(menubar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        menu_program = new QMenu(menubar);
        menu_program->setObjectName(QString::fromUtf8("menu_program"));
        LocalMode->setMenuBar(menubar);
        statusbar = new QStatusBar(LocalMode);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LocalMode->setStatusBar(statusbar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_edit->menuAction());
        menubar->addAction(menu_program->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(action_new);
        menu_file->addAction(action_open);
        menu_file->addAction(action_save);
        menu_file->addAction(action_save_as);
        menu_file->addAction(action_exit);
        menu_file->addSeparator();
        menu_file->addAction(action_upload);
        menu_edit->addAction(action_copy);
        menu_edit->addAction(action_cut);
        menu_edit->addAction(action_paste);
        menu_help->addAction(action_help);
        menu_program->addAction(action_run);
        menu_program->addAction(action_procedures);
        menu_program->addAction(action_debug);

        retranslateUi(LocalMode);

        QMetaObject::connectSlotsByName(LocalMode);
    } // setupUi

    void retranslateUi(QMainWindow *LocalMode)
    {
        LocalMode->setWindowTitle(QApplication::translate("LocalMode", "MainWindow", nullptr));
        action_new->setText(QApplication::translate("LocalMode", "\346\226\260\345\273\272", nullptr));
        action_open->setText(QApplication::translate("LocalMode", "\346\211\223\345\274\200", nullptr));
        action_save->setText(QApplication::translate("LocalMode", "\344\277\235\345\255\230", nullptr));
        action_save_as->setText(QApplication::translate("LocalMode", "\345\217\246\345\255\230\344\270\272", nullptr));
        action_exit->setText(QApplication::translate("LocalMode", "\351\200\200\345\207\272", nullptr));
        action_copy->setText(QApplication::translate("LocalMode", "\345\244\215\345\210\266", nullptr));
        action_cut->setText(QApplication::translate("LocalMode", "\345\211\252\345\210\207", nullptr));
        action_paste->setText(QApplication::translate("LocalMode", "\347\262\230\350\264\264", nullptr));
        action_help->setText(QApplication::translate("LocalMode", "\345\270\256\345\212\251\346\226\207\346\241\243", nullptr));
        action_upload->setText(QApplication::translate("LocalMode", "\344\270\212\344\274\240\350\207\263\347\244\276\345\214\272", nullptr));
        action_run->setText(QApplication::translate("LocalMode", "\350\277\220\350\241\214", nullptr));
        action_procedures->setText(QApplication::translate("LocalMode", "\345\255\220\347\250\213\345\272\217\350\241\250", nullptr));
        action_debug->setText(QApplication::translate("LocalMode", "\350\260\203\350\257\225", nullptr));
        action_build->setText(QApplication::translate("LocalMode", "\346\236\204\345\273\272", nullptr));
        menu_file->setTitle(QApplication::translate("LocalMode", "\346\226\207\344\273\266", nullptr));
        menu_edit->setTitle(QApplication::translate("LocalMode", "\347\274\226\350\276\221", nullptr));
        menu_help->setTitle(QApplication::translate("LocalMode", "\345\270\256\345\212\251", nullptr));
        menu_program->setTitle(QApplication::translate("LocalMode", "\347\250\213\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LocalMode: public Ui_LocalMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALMODE_H
