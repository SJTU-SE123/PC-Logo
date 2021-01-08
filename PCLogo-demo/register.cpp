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
    this->setFixedSize(668, 668);
    QPalette palette;
    QPixmap pixmap(":/image/register.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    this->ui->label->setStyleSheet("background-image: url(:/image/username.png);");
    this->ui->label_2->setStyleSheet("background-image: url(:/image/password.png);");
    this->ui->label_3->setStyleSheet("background-image: url(:/image/passwordAgain.png);");
    this->ui->pushButton->setStyleSheet("background-image: url(:/image/regibtn.png);");
    this->ui->backButton->setStyleSheet("background-image: url(:/image/regibackbtn.png);");
    this->ui->pushButton->setFlat(true);
    this->ui->backButton->setFlat(true);
    this->ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    this->ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finishRequest(QNetworkReply*)));
}

Register::~Register()
{
    delete ui;
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
        QMessageBox::information(this, "错误", "无法连接到服务器，请联系管理员或稍后再试。", "确定");
    }
    reply->deleteLater();
}

void Register::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    qDebug() << username;
    QString password = ui->lineEdit_2->text();
    QString repeatPass = ui->lineEdit_3->text();
    if(username.isEmpty() || password.isEmpty() || repeatPass.isEmpty()) {
        QMessageBox::information(this, "错误", "请输入完整信息！", "确定");
        return;
    }
    if(password != repeatPass) {
        QMessageBox::information(this, "错误", "两次密码不一致！", "确定");
        return;
    }
    else{
        QJsonObject json;

        json.insert("username",username);
        json.insert("password",password);

        QJsonDocument document;
        document.setObject(json);

        QByteArray data = document.toJson(QJsonDocument::Compact);
        QString URL = "http://121.4.198.32:8080/user/register";

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Accept", "*/*");
        request.setUrl(QUrl(URL));

        manager.post(request, data);
    }
}

void Register::on_backButton_clicked()
{
    this->close();
}
