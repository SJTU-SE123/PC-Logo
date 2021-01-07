#ifndef Chat_H
#define Chat_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QGraphicsOpacityEffect>
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
class Chat;
}

class Chat : public QMainWindow
{
    Q_OBJECT

public:
    Chat(QString username);
    ~Chat();
    QString getIp();
    QString getUsername();
    void draw(QString str);
    void sendMsg(QJsonObject msg);
    void appendMsg(QString fromUser, QString text, QString time);
    void setPartner(QString fromUser);
    void resetContent();
    QString getPartner();
    QString getText();

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void sendMessage(QString msg);

private:
    Ui::Chat *ui;
    Canvas *canvas;
    LineInterpreter *lineInterpreter;
    QWebSocket m_webSocket;
    QString partner;
    QString username;
    const double OPACITY = 0.8;
    QGraphicsOpacityEffect *canvas_opacity;

private slots:
    void on_sendButton_clicked();
    void on_exitButton_clicked();
};

#endif // Chat_H
