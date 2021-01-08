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
    void finishRequest(QNetworkReply *reply);

    void on_pushButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Register *ui;
    QNetworkAccessManager manager;
    QNetworkRequest request;
};

#endif // REGISTER_H
