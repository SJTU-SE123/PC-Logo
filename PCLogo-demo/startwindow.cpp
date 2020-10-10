#include "startwindow.h"
#include "ui_startwindow.h"
#include "localmode.h"
#include "netmode.h"
#include <QMenu>
#include "register.h"
#include "login.h"
#include "userinfo.h"
//#include <QDebug>

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    ui->otherButton->setStyleSheet("border: 0px;");
    gif = new QMovie(":/image/crawling.gif");
    gifPlayer = new QLabel(this);
    gifPlayer->setMovie(gif);
    gif->start();
    gifPlayer->setGeometry(30, 10, 340, 130);

    this->setWindowTitle("PC Logo 开始");
    logoWindow = nullptr;
    t = nullptr;
//    ui->LocalMode->setStyleSheet("border-image: url(:/image/crawling.gif)");
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_LocalMode_clicked()
{
    if (logoWindow != nullptr) {
        delete logoWindow;
        logoWindow = nullptr;
    }
    logoWindow = new LocalMode();
    logoWindow->show();
//    this->hide();
}

void StartWindow::on_NetMode_clicked()
{
    if (logoWindow != nullptr) {
        delete logoWindow;
        logoWindow = nullptr;
    }
    logoWindow = new NetMode();
    logoWindow->show();
//    this->hide();
}

void StartWindow::on_Exit_clicked()
{
    qApp->closeAllWindows();
}

void StartWindow::on_otherButton_clicked()
{
    QMenu *pMenu = new QMenu(this);
    QAction *pRegiTask = new QAction(tr("注册"), this);
    QAction *pLoginTask = new QAction(tr("登录"), this);
    QAction *pInfoTask = new QAction(tr("用户信息"), this);

    pRegiTask->setData(1);
    pLoginTask->setData(2);
    pInfoTask->setData(3);
    pMenu->addAction(pRegiTask);
    pMenu->addAction(pLoginTask);
    pMenu->addAction(pInfoTask);

    connect(pRegiTask, SIGNAL(triggered()), this, SLOT(onTaskBoxContextMenuEvent()));
    connect(pLoginTask, SIGNAL(triggered()), this, SLOT(onTaskBoxContextMenuEvent()));
    connect(pInfoTask, SIGNAL(triggered()), this, SLOT(onTaskBoxContextMenuEvent()));

    pMenu->exec(cursor().pos());

    QList<QAction*> list = pMenu->actions();
    foreach (QAction* pAction, list) delete pAction;
    delete pMenu;
}

void StartWindow::onTaskBoxContextMenuEvent(){
    QAction *pEven = qobject_cast<QAction *>(this->sender());
    int iType = pEven->data().toInt();
    switch (iType){
        case 1:
            if (t != nullptr){
                delete t;
                t = nullptr;
            }
            t = new Register();
            t->show();
            break;
        case 2:
            if (t != nullptr){
                delete t;
                t = nullptr;
            }
            t = new Login();
            t->show();
            break;
        case 3:
            if (t != nullptr){
                delete t;
                t = nullptr;
            }
            t = new UserInfo();
            t->show();
            break;
        default: break;
    }
}
