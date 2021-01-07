#ifndef ADVANCEDCHAT_H
#define ADVANCEDCHAT_H

#include <QMainWindow>
#include <QGraphicsOpacityEffect>
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
    void setPartner(QString fromUser, bool isP2 = false);
    void resetContent();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_sendButton_clicked();
    void on_exitButton_clicked();

private:
    bool isP2;
    Ui::AdvancedChat *ui;
    Canvas *canvas;
    LineInterpreter *lineInterpreter;
    QWebSocket m_webSocket;
    QString partner;
    QString username;
    const double OPACITY = 0.8;
    QGraphicsOpacityEffect *canvas_opacity;

signals:
    void sendMessage(QString msg);
};

#endif // ADVANCEDCHAT_H
