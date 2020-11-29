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
#include "canvas.h"
#include "codeeditor.h"

class QUdpSocket;
enum MessageType {NewParticipant,ParticipantLeft};

namespace Ui {
class NetMode;
}

class NetMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit NetMode(QWidget *parent = nullptr);
    ~NetMode();

private:
    Ui::NetMode *ui;
    QUdpSocket *udpSocket;
    qint16 port;

protected:
    void newParticipant(QString userName, QString localHostName,QString ipAddress);
    void participantLeft(QString localHostName);
    void sendMessage(MessageType type);
    QString getIP();
    QString getUserName();

private slots:
    void processPendingDatagrams();

};

#endif // NETMODE_H
