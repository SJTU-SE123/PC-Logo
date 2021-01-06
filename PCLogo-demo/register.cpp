#include "register.h"
#include "ui_register.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonObject>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 注册");
    connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finishRequest(QNetworkReply*)));
}

Register::~Register()
{
    delete ui;
}

void Register::on_registerButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    QString repeatPass = ui->repeatPassword->text();
    if(username.isEmpty() || password.isEmpty() || repeatPass.isEmpty()) {
        QMessageBox::warning(this,"Warning","请输入完整信息！",QMessageBox::Yes);
    }
    else{
        QJsonObject json;

        json.insert("username",username);
        json.insert("password",password);

        QJsonDocument document;
        document.setObject(json);

        QByteArray data = document.toJson(QJsonDocument::Compact);
        QString URL = "http://localhost:8080/user/register";

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Accept", "*/*");
        request.setUrl(QUrl(URL));

        manager.post(request, data);
    }
}

void Register::finishRequest(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray bytes = reply->readAll();
        qDebug() << bytes;
        QJsonObject response = QJsonDocument::fromJson(bytes).object();
        int status = response.value("status").toInt();
        if(status == 0) {
            QMessageBox::information(this, "注册成功", "注册成功！", "确定");
            this->close();
        } else {
            QMessageBox::information(this, "错误", "注册失败，要不换一个用户名试试？", "确定");
        }
    } else {
        qDebug( "found error .... code: %d\n", static_cast<int>(reply->error()));
    }
    reply->deleteLater();
}
