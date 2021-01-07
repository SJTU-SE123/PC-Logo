#ifndef NETMODE_H
#define NETMODE_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsOpacityEffect>
#include <QtWebSockets>
#include "codeeditor.h"
#include "canvas.h"
#include "chat.h"
#include "advancedchat.h"

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

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::NetMode *ui;
    QWebSocket m_webSocket;
    QUrl m_url;
    bool m_debug;
    QList<QString> userList;
    QList<bool>statusList;
    QString username;
    QString partner;
    Chat *chat;
    AdvancedChat *advChat;
    QString type;
    QGraphicsOpacityEffect *opacity;
    const double OPACITY = 0.8;

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
