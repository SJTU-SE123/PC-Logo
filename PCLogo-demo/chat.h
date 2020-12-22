#ifndef Chat_H
#define Chat_H

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
#include "canvas.h"
#include "codeeditor.h"
#include "lineinterpreter.h"

enum MessageType
{
    NewParticipant,
    ParticipantLeft,
    Message,
    Exit
};

namespace Ui {
class Chat;
}

class Chat : public QMainWindow
{
    Q_OBJECT

public:
    Chat(QString oppUserName, QString oppUserIp);
    ~Chat();
    QString getIp();
    QString getUsername();
    void sendMessage(MessageType type);
    void draw(QString str);


private:
    Ui::Chat *ui;
    Canvas *canvas;
    QString oppUserName, oppUserIp;
    QUdpSocket *chatUdp;
    qint32 chatPort;
    LineInterpreter *lineInterpreter;

private slots:
    void processPendingDatagrams();
    void on_sendButton_clicked();
    void on_exitButton_clicked();
};

#endif // Chat_H
