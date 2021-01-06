#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

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

private:
    Ui::Login *ui;
    QNetworkAccessManager manager;   //manager  相关注意点见后文
    QNetworkRequest request;    //request
};

#endif // LOGIN_H
