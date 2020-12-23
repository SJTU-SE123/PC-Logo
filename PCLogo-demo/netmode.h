#ifndef NETMODE_H
#define NETMODE_H

#include <QMainWindow>
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QColorDialog>
#include <QTextCharFormat>
#include <QModelIndex>
#include <QtWebSockets/QWebSocket>
#include "canvas.h"
#include "codeeditor.h"
#include "chat.h"
#include "login.h"

namespace Ui {
class NetMode;
}

class NetMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit NetMode(QString username, QWidget *parent = nullptr);
    ~NetMode();
    void sendMsg(QJsonObject msg);

private:
    Ui::NetMode *ui;
    QWebSocket m_webSocket;
    QUrl m_url;
    bool m_debug;
    QList<QString> users;
    QString username;
    QString partner;
    Chat *chat;

signals:
    void closed();

private slots:
    void paintEvent(QPaintEvent*) override;
    void onConnected();
    void onTextMessageReceived(QString message);
    void on_tableWidget_doubleClicked(QModelIndex index);
    void onSendMessage(QString msg);
};

#endif // NETMODE_H
