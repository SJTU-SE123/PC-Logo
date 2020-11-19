#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_OKButton_clicked();
    void finishRequest(QNetworkReply*);  //处理reply的slot
    void dealRequest(QNetworkReply*);

    void on_RegButton_clicked();

private:
    Ui::login *ui;
    QNetworkAccessManager manager;   //manager  相关注意点见后文
    QNetworkRequest request;    //request

};

#endif // LOGIN_H
