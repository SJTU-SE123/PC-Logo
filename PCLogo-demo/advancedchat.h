#ifndef ADVANCEDCHAT_H
#define ADVANCEDCHAT_H

#include <QMainWindow>
#include <QCloseEvent>
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
#include <QtWebSockets/QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include "canvas.h"
#include "codeeditor.h"
#include "lineinterpreter.h"

namespace Ui {
class AdvancedChat;
}

class AdvancedChat : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdvancedChat(QString username);
    ~AdvancedChat();
    QString getIp();
    QString getUsername();
    void draw(bool flag, QString str);
    void sendMsg(QJsonObject msg);
    void appendMsg(QString fromUser, QString text, QString time);
    void setPartner(QString fromUser);
    QString getPartner();
    void resetContent();
    QString getText();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_sendButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::AdvancedChat *ui;
    Canvas *canvas1;
    Canvas *canvas2;
    LineInterpreter *lineInterpreter;
    QWebSocket m_webSocket;
    QString partner;
    QString username;

signals:
    void sendMessage(QString msg);
};

#endif // ADVANCEDCHAT_H
