#include "login.h"
#include "register.h"
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
    QPalette palette;
    QPixmap pixmap(":/image/login.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    this->ui->label->setStyleSheet("background-image: url(:/image/username.png);");
    this->ui->label_2->setStyleSheet("background-image: url(:/image/password.png);");
    this->ui->pushButton->setStyleSheet("background-image: url(:/image/loginbtn.png);");
    this->ui->backButton->setStyleSheet("background-image: url(:/image/backbtn.png);");
    this->ui->registerButton->setStyleSheet("background-image: url(:/image/openregisterbtn.png);");
    connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finishRequest(QNetworkReply*)));
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this,"Warning","用户名或密码为空！",QMessageBox::Yes);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
    }
    else{
        //通过QJsonObject得到post需要的参数data， data形式为： "data={"username": "haha","passwd": 123456}"

        QJsonObject json;

        json.insert("username",username);
        json.insert("password",password);


        QJsonDocument document;
        document.setObject(json);

        QByteArray data = document.toJson(QJsonDocument::Compact);
        QString URL = "http://localhost:8080/login?";
        URL = URL + "username=" + username + "&" + "password=" + password;

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");  //上面语句固定这么写，要不然会报错“contest—type is missing”
        request.setRawHeader("Accept", "*/*");
        request.setUrl(QUrl(URL));  //"http："不要少

        manager.post(request,data);
    }
}

void Login::finishRequest(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray bytes = reply->readAll();
        QJsonObject response = QJsonDocument::fromJson(bytes).object();
        int status = response.value("status").toInt();
        if(status == 0) {
            QJsonObject extraData = response.value("extraData").toObject();
            QString username = extraData.value("username").toString();
            qDebug() << "login success, username is " << username;
            QMessageBox::information(this, "登录成功", "登录成功！", "确定");
            UserLogin(username);
            this->close();
        } else {
            QMessageBox::information(this, "错误", "用户名或密码错误！", "确定");
        }
    } else {
        qDebug( "found error .... code: %d\n", static_cast<int>(reply->error()));
    }
    reply->deleteLater();
}

void Login::on_registerButton_clicked()
{
    if(registerWindow == nullptr) {
        delete registerWindow;
        registerWindow = new Register();
    }
    registerWindow->show();
}

void Login::on_backButton_clicked()
{
    this->close();
}
