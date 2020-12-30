#include "userinfo.h"
#include "ui_userinfo.h"

UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 用户信息");
}

UserInfo::~UserInfo()
{
    delete ui;
}
