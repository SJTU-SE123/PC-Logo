#include "netmode.h"
#include "ui_netmode.h"
#include <QToolButton>
#include "codeeditor.h"
#include "connect.h"

NetMode::NetMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NetMode)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);
    port = 45454;
    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    sendMessage(NewParticipant);
}


NetMode::~NetMode() {
    delete ui;
}

QString NetMode::getIP() {
    QList<QHostAddress>list = QNetworkInterface::allAddresses();
    foreach(QHostAddress address,list) {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            return address.toString();
    }
    return 0;
}

QString NetMode::getUserName() {
    QStringList envVariables;
    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";
    QStringList environment = QProcess::systemEnvironment();
    foreach(QString string,envVariables) {
        int index = environment.indexOf(QRegExp(string));
        if(index != -1) {
            QStringList stringList = environment.at(index).split('=');
            if(stringList.size() == 2) {
                return stringList.at(1);
            }
        }
    }
    return "unKnow";
}

void NetMode::sendMessage(MessageType type) {
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    QString localHostName = QHostInfo::localHostName();
    QString address = getIP();
    out << type << getUserName() << localHostName;
    QString clientAddress;
    switch(type) {
        case NewParticipant: {
            out << address;
            break;
        }
        case ParticipantLeft:
            break;
    }
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);
}

void NetMode::newParticipant(QString userName, QString localHostName, QString ipAddress) {
//    bool isEmpty = ui->tableWidget
//            ->findItems(localHostName,Qt::MatchExactly).isEmpty();
    //if(isEmpty) {
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);

        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,user);
        ui->tableWidget->setItem(0,1,host);
        ui->tableWidget->setItem(0,2,ip);
        //sendMessage(NewParticipant);
    //}
}

void NetMode::participantLeft(QString localHostName)
{
    int rowNum = ui->tableWidget->findItems(localHostName, Qt::MatchExactly).first()->row();
    ui->tableWidget->removeRow(rowNum);
}

void NetMode::processPendingDatagrams() {
    while(udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        int messageType;
        in >> messageType;
        QString clientAddress,fileName;
        QString userName,localHostName,ipAddress,message;
        QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        switch(messageType) {
            case NewParticipant:
                in >> userName >> localHostName >> ipAddress;
                newParticipant(userName,localHostName,ipAddress);
                break;

            case ParticipantLeft:
                in >> userName >> localHostName;
                participantLeft(localHostName);
        }
    }
}

void NetMode::on_tableWidget_doubleClicked(QModelIndex index) {
    privateChat = new Chat(ui->tableWidget->item(index.row(),1)->text(), //接收主机名
                   ui->tableWidget->item(index.row(),2)->text()) ;//接收用户IP
    privateChat->show();
}


