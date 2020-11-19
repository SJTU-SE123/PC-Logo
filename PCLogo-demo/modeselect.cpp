#include "modeselect.h"
#include "ui_modeselect.h"
#include "localmode.h"
#include "netmode.h"

ModeSelect::ModeSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModeSelect)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 选择模式");
    logoWindow = nullptr;
    QPalette palette;
    QPixmap pixmap(":/image/selectmode.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    ui->LocalMode->setStyleSheet("background-image: url(:/image/localmode.png);");
    ui->NetMode->setStyleSheet("background-image: url(:/image/netmode.png);");
    ui->Tutorial->setStyleSheet("background-image: url(:/image/tutorial.png);");
}

ModeSelect::~ModeSelect()
{
    delete ui;
}

void ModeSelect::on_LocalMode_clicked()
{
    if (logoWindow != nullptr){
        delete logoWindow;
        logoWindow = nullptr;
    }
    logoWindow = new LocalMode();
    logoWindow->show();
}

void ModeSelect::on_NetMode_clicked()
{
    if (logoWindow != nullptr){
        delete logoWindow;
        logoWindow = nullptr;
    }
    logoWindow = new NetMode();
    logoWindow->show();
}

void ModeSelect::on_Tutorial_clicked()
{

}
