#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonObject>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 登录");
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
//    if(username.isEmpty() || password.isEmpty()) {
//        QMessageBox::warning(this,"Warning","Username or password is empty!",QMessageBox::Yes);
//        ui->lineEdit->clear();
//        ui->lineEdit_2->clear();
//    }
//    else{
//        //通过QJsonObject得到post需要的参数data， data形式为： "data={"username": "haha","passwd": 123456}"

//        QJsonObject json;

//        json.insert("username",username);
//        json.insert("password",password);


//        QJsonDocument document;
//        document.setObject(json);

//        QByteArray data = document.toJson(QJsonDocument::Compact);
//        QString URL = "http://localhost:9090/login?";
//        URL = URL + "username=" + username + "&" + "password=" + password;

//        qDebug(data);

//        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");  //上面语句固定这么写，要不然会报错“contest—type is missing”
//        request.setRawHeader("Accept", "*/*");
//        request.setUrl(QUrl(URL));  //"http："不要少

//        manager.post(request,data);
//        connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finishRequest(QNetworkReply*)));
//    }
    UserLogin(username);
    close();
}
