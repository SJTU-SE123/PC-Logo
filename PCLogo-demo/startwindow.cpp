#include "startwindow.h"
#include "ui_startwindow.h"
#include "localmode.h"
#include "netmode.h"

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    gif = new QMovie(":/image/crawling.gif");
    gifPlayer = new QLabel(this);
    gifPlayer->setMovie(gif);
    gif->start();
    gifPlayer->setGeometry(30, 10, 340, 130);

    this->setWindowTitle("PC Logo 开始");
    logoWindow = nullptr;
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
