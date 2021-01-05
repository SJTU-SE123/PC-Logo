#ifndef AdvancedChat_H
#define AdvancedChat_H

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
    AdvancedChat(QString username);
    ~AdvancedChat();
    QString getIp();
    QString getUsername();
    void draw(QString str);
    void sendMsg(QJsonObject msg);
    void appendMsg(QString fromUser, QString text, QString time);
    void setPartner(QString fromUser);

signals:
    void sendMessage(QString msg);

private:
    Ui::AdvancedChat *ui;
    Canvas *canvas;
    LineInterpreter *lineInterpreter;
    QWebSocket m_webSocket;
    QString partner;
    QString username;

private slots:
    void on_sendButton_clicked();
    void on_exitButton_clicked();
};

#endif // AdvancedChat_H
