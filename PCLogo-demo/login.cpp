#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 登录");
}

// 首页登录 / 点击联机模式发现没有登录 进行登录
// 首页登录之后 将username保存在startWindow 传给 modeSelect netMode
// 通过联机模式登录之后 将username 保存在startWindow 和 netMode


Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    // 登录逻辑还没写。。。
    UserLogin(username);
    close();
}
