#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_registerButton_clicked();
    void finishRequest(QNetworkReply *reply);

private:
    Ui::Register *ui;
    QNetworkAccessManager manager;
    QNetworkRequest request;
};

#endif // REGISTER_H
