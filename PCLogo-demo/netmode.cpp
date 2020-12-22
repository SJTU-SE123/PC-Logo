#include "netmode.h"
#include "ui_netmode.h"
#include <QToolButton>
#include "codeeditor.h"
#include "connect.h"
#include <QtCore/QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>

NetMode::NetMode(QString username, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NetMode)
{
    ui->setupUi(this);
    this->username = username;
    this->m_url = "ws://localhost:8080/online/" + this->username;
    this->m_debug = true;
    connect(&m_webSocket, &QWebSocket::connected, this, &NetMode::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &NetMode::closed);
    m_webSocket.open(QUrl(m_url));

//    udpSocket = new QUdpSocket(this);
//    port = 45454;
//    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
//    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
//    newParticipant(getUserName(), QHostInfo::localHostName(), getIP());
//    sendMessage(NewParticipant);
}

void NetMode::paintEvent(QPaintEvent*) {
    // update 好像是重绘 所以不用清空
    for (auto user : this->users) {
        QTableWidgetItem *up = new QTableWidgetItem(user);
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,up);
    }
}

void NetMode::onConnected() {
    if (m_debug) qDebug() << "WebSocket connected";
    connect(&m_webSocket, &QWebSocket::textMessageReceived, this, &NetMode::onTextMessageReceived);
}

void NetMode::onTextMessageReceived(QString message) {
    if (m_debug) qDebug() << "Message received:" << message;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(message.toLocal8Bit().data());
    QJsonObject jsonObject = jsonDocument.object();
    for (QJsonObject::Iterator it = jsonObject.begin(); it != jsonObject.end(); it++) {
        if (m_debug) qDebug() << "key: " << it.key() << ", value: " << it.value() << endl;

        // 更新在线用户列表
        if (it.key() == "onlineUsers") {
            QJsonArray users = it.value().toArray();
            QList<QString> usernames;
            for (QJsonArray::Iterator user = users.begin(); user != users.end(); user++) {
                QString username = (*user).toString();
                usernames.append(username);
            }
            this->users = usernames;
            update();
        }

        //
    }
}


NetMode::~NetMode() {
    delete ui;
}

//QString NetMode::getIP() {
//    QList<QHostAddress>list = QNetworkInterface::allAddresses();
//    foreach(QHostAddress address,list) {
//        if(address.protocol() == QAbstractSocket::IPv4Protocol)
//            return address.toString();
//    }
//    return 0;
//}

//QString NetMode::getUserName() {
//    QStringList envVariables;
//    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
//                 << "HOSTNAME.*" << "DOMAINNAME.*";
//    QStringList environment = QProcess::systemEnvironment();
//    foreach(QString string,envVariables) {
//        int index = environment.indexOf(QRegExp(string));
//        if(index != -1) {
//            QStringList stringList = environment.at(index).split('=');
//            if(stringList.size() == 2) {
//                return stringList.at(1);
//            }
//        }
//    }
//    return "unKnow";
//}

//void NetMode::sendMessage(MessageType type) {
//    QByteArray data;
//    QDataStream out(&data,QIODevice::WriteOnly);
//    QString localHostName = QHostInfo::localHostName();
//    QString address = getIP();
//    out << type << getUserName() << localHostName;
//    QString clientAddress;
//    switch(type) {
//        case NewParticipant: {
//            out << address;
//            break;
//        }
//        case ParticipantLeft:
//            break;
//    }
//    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);
//}

//void NetMode::newParticipant(QString userName, QString localHostName, QString ipAddress) {
////    bool isEmpty = ui->tableWidget
////            ->findItems(localHostName,Qt::MatchExactly).isEmpty();
//    //if(isEmpty) {
//        QTableWidgetItem *user = new QTableWidgetItem(userName);
//        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
//        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);

//        ui->tableWidget->insertRow(0);
//        ui->tableWidget->setItem(0,0,user);
//        ui->tableWidget->setItem(0,1,host);
//        ui->tableWidget->setItem(0,2,ip);
//        //sendMessage(NewParticipant);
//    //}
//}

//void NetMode::participantLeft(QString localHostName)
//{
//    int rowNum = ui->tableWidget->findItems(localHostName, Qt::MatchExactly).first()->row();
//    ui->tableWidget->removeRow(rowNum);
//}

//void NetMode::processPendingDatagrams() {
//    while(udpSocket->hasPendingDatagrams()) {
//        QByteArray datagram;
//        datagram.resize(udpSocket->pendingDatagramSize());
//        udpSocket->readDatagram(datagram.data(),datagram.size());
//        QDataStream in(&datagram,QIODevice::ReadOnly);
//        int messageType;
//        in >> messageType;
//        QString clientAddress,fileName;
//        QString userName,localHostName,ipAddress,message;
//        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
//        switch(messageType) {
//            case NewParticipant:
//                in >> userName >> localHostName >> ipAddress;
//                qDebug() << userName;
//                qDebug() << getUserName();
//                if (userName == getUserName()) continue;
//                newParticipant(userName,localHostName,ipAddress);
//                sendMessage(NewParticipant);
//                break;

//            case ParticipantLeft:
//                in >> userName >> localHostName;
//                participantLeft(localHostName);
//        }
//    }
//}

//void NetMode::on_tableWidget_doubleClicked(QModelIndex index) {
//    privateChat = new Chat(ui->tableWidget->item(index.row(),1)->text(), //接收主机名
//                   ui->tableWidget->item(index.row(),2)->text()) ;//接收用户IP
//    privateChat->show();
//}


