#include "chat.h"
#include "ui_chat.h"
#include <QToolButton>

Chat::Chat(QString oppUserName, QString oppUserIp) :
    ui(new Ui::Chat) {
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 联网");
    canvas = new Canvas(this);
    canvas->setGeometry(420, 10, 370, 460);
    canvas->setStyleSheet("background-color: white; border: 1px solid #555555;");
    canvas->setPos(185, 230);
    this->oppUserName = oppUserName;
    this->oppUserIp = oppUserIp;
    chatUdp = new QUdpSocket(this);
    chatPort = 45456;
    chatUdp->bind(QHostAddress(getIp()), chatPort);
    connect(chatUdp, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}

Chat::~Chat() {}


QString Chat::getIp() {
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list) {
       if(address.protocol() == QAbstractSocket::IPv4Protocol) //我们使用IPv4地址
            return address.toString();
    }
    return nullptr;
}

QString Chat::getUsername() {
    QStringList envVariables;
    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";
    QStringList environment = QProcess::systemEnvironment();
    foreach (QString string, envVariables) {
        int index = environment.indexOf(QRegExp(string));
        if (index != -1) {
            QStringList stringList = environment.at(index).split('=');
            if (stringList.size() == 2) {
                return stringList.at(1);
            }
        }
    }
    return nullptr;
}

void Chat::processPendingDatagrams() {
    while(chatUdp->hasPendingDatagrams()) {
       QByteArray datagram;
       datagram.resize(chatUdp->pendingDatagramSize());
       chatUdp->readDatagram(datagram.data(),datagram.size());
       QDataStream in(&datagram,QIODevice::ReadOnly);
       int messageType;
       in >> messageType;
       QString userName,localHostName,ipAddress,messagestr;
       QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
       switch(messageType) {
           case Message: {
               in >>userName >>localHostName >>ipAddress >>messagestr;
               ui->textBrowser->setTextColor(Qt::red);
               ui->textBrowser->setCurrentFont(QFont("Times New Roman",12));
               ui->textBrowser->append("[ " +localHostName+" ] "+ time);//与主机名聊天中
               ui->textBrowser->append(messagestr);
               this->draw(messagestr);
           }
           case Exit: {

           }
       }
    }
}

void Chat::on_sendButton_clicked() {
    QString localHostName = QHostInfo::localHostName();
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->textBrowser->setTextColor(Qt::blue);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman",12));
    ui->textBrowser->append("[ " +localHostName+" ] "+ time);
    QString msg = ui->textEdit->toPlainText();
    ui->textBrowser->append(msg);
    qDebug() << msg;
    ui->textEdit->clear();
    ui->textEdit->setFocus();
    this->sendMessage(Message);
    this->draw(msg);
    return;
}

void Chat::sendMessage(MessageType type) {
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    QString localHostName = QHostInfo::localHostName();
    QString address = getIp();
    out << type << getUsername() << localHostName;
    switch(type) {
        case Message: {
            QString msg = ui->textEdit->toPlainText();
            out << address << msg;
            //ui->textBrowser->verticalScrollBar()->setValue(ui->textBrowser->verticalScrollBar()->maximum());
        }
        case Exit: {

        }
    }
    chatUdp->writeDatagram(data,data.length(), QHostAddress(oppUserIp), 45456);
}

void Chat::on_exitButton_clicked() {

}

void Chat::draw(QString str) {
    command* cmd = this->lineInterpreter->parseLine(str);
    this->canvas->parseCommand(cmd);
}
