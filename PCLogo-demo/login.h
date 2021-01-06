#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include "register.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void UserLogin(QString username);

private slots:
    void on_pushButton_clicked();
    void finishRequest(QNetworkReply *reply);
    void on_registerButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Login *ui;
    QNetworkAccessManager manager;   //manager  相关注意点见后文
    QNetworkRequest request;    //request
    Register *registerWindow = nullptr;
};

#endif // LOGIN_H
