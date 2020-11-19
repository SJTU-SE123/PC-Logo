#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QByteArray>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonObject>
#include <QDebug>
#include <iostream>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

}

login::~login()
{
    delete ui;
}

void login::on_OKButton_clicked()
{
    //获取用户名、密码
        QString username = ui->usrlineEdit->text();
        QString password = ui->pwdlineEdit->text();
        if(username.isEmpty() || password.isEmpty())
        {
            QMessageBox::warning(this,"Warning","Username or password is empty!",QMessageBox::Yes);
            ui->usrlineEdit->clear();
            ui->pwdlineEdit->clear();
        }
        else{
        //通过QJsonObject得到post需要的参数data， data形式为： "data={"username": "haha","passwd": 123456}"

        QJsonObject json;

        json.insert("username",username);
        json.insert("password",password);


        QJsonDocument document;
        document.setObject(json);

        QByteArray data = document.toJson(QJsonDocument::Compact);
//        QByteArray data;
//        data.append(byte_array);

        QString URL = "http://localhost:9090/login?";
        URL = URL + "username=" + username + "&" + "password=" + password;

        qDebug(data);

        //设置request
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");  //上面语句固定这么写，要不然会报错“contest—type is missing”
        request.setRawHeader("Accept", "*/*");
        request.setUrl(QUrl(URL));  //"http："不要少

        //manager发送请求，并接收reply，委托给slot处理
        manager.post(request,data);
        connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(finishRequest(QNetworkReply*)));
      }
}


void login::finishRequest(QNetworkReply *reply)
{
    if (reply->error()){
            qDebug()<<"Error!";
    }else{
            //解析reply中携带的Json
            qDebug()<<"Step1!";
            QByteArray byte_array = reply->readAll();  //Json ducument
            QJsonParseError json_error;
            QJsonDocument parse_document = QJsonDocument::fromJson(byte_array, &json_error);

            if(json_error.error == QJsonParseError::NoError)
            {
                qDebug()<<"Step2!";
                if(parse_document.isObject())
                  {
                    qDebug()<<"Step3!";
                    QJsonObject obj = parse_document.object();
                      if(obj.contains("status"))
                      {
                          qDebug()<<"Step4!";
                          QJsonValue code_value = obj.take("status");
                          int code_value_int = code_value.toInt();
                          if(code_value_int == 0)
                          {
                              QJsonValue message_value = obj.take("message");
                              qDebug()<<message_value<<endl;  //输出：QJsonValue(string, "登录成功")
                              QString success_message = message_value.toString();
                              QMessageBox::warning(this,"Success",success_message,QMessageBox::Yes);
                          }
                          else
                          {
                              QJsonValue message_value = obj.take("message");
                              qDebug()<< message_value<<endl;
                              QString error_message = message_value.toString();
                              QMessageBox::warning(this,"Error",error_message,QMessageBox::Yes);
                              ui->usrlineEdit->clear();
                              ui->pwdlineEdit->clear();

                          }
                    }
               }
           }
    }
     reply->deleteLater();
}

void login::dealRequest(QNetworkReply *reply)
{
    if (reply->error()){
            qDebug()<<"Error!";
    }else{
            //解析reply中携带的Json
            qDebug()<<"Step1!";
            QByteArray byte_array = reply->readAll();  //Json ducument
            QJsonParseError json_error;
            QJsonDocument parse_document = QJsonDocument::fromJson(byte_array, &json_error);

            if(json_error.error == QJsonParseError::NoError)
            {
                qDebug()<<"Step2!";
                if(parse_document.isObject())
                  {
                    qDebug()<<"Step3!";
                    QJsonObject obj = parse_document.object();
                      if(obj.contains("status"))
                      {
                          qDebug()<<"Step4!";
                          QJsonValue code_value = obj.take("status");
                          int code_value_int = code_value.toInt();
                          if(code_value_int == 0)
                          {
                              QJsonValue message_value = obj.take("message");
                              qDebug()<<message_value<<endl;  //输出：QJsonValue(string, "登录成功")
                          }
                          else
                          {
                              QJsonValue message_value = obj.take("message");
                              qDebug()<< message_value<<endl;
                              QString error_message = message_value.toString();
                              QMessageBox::warning(this,"Error",error_message,QMessageBox::Yes);
                              ui->usrlineEdit->clear();
                              ui->pwdlineEdit->clear();

                          }
                    }
               }
           }
    }
     reply->deleteLater();
}

void login::on_RegButton_clicked()
{
    QString username = ui->usrlineEdit->text();
    QString password = ui->pwdlineEdit->text();
    QString mailAddr = ui->ElineEdit->text();
    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this,"Warning","Username or password is empty!",QMessageBox::Yes);
        ui->usrlineEdit->clear();
        ui->pwdlineEdit->clear();
    }
    else{
    //通过QJsonObject得到post需要的参数data， data形式为： "data={"username": "haha","passwd": 123456}"

    QJsonObject json;
    json.insert("username",username);
    json.insert("password",password);
    json.insert("mailAddr",mailAddr);

    QJsonDocument document;
    document.setObject(json);

    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QByteArray data;
    data.append(byte_array);

//    QString URL = "http://localhost:9090/user/register?";
//    URL = URL + "username=" + username + "&" + "password=" + password + "&" + "mailAddr=" + mailAddr;

    qDebug(data);

    //设置request
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");  //上面语句固定这么写，要不然会报错“contest—type is missing”
//        request.setRawHeader("XXX3", "XXX4");
//        request.setRawHeader("Host", "www.baidu.com");
//        request.setRawHeader("User-Agent", "curl/7.55.1");
//    request.setRawHeader("Accept", "*/*");
        request.setRawHeader("Connection", "keep-alive");
//        request.setRawHeader("Accept-Encoding", "*");
    request.setUrl(QUrl("http://localhost:9090/user/register"));  //"http："不要少

    //manager发送请求，并接收reply，委托给slot处理
    manager.post(request,data);
    connect(&manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(dealRequest(QNetworkReply*)));
  }
}
