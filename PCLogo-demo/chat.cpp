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
    return 0;
}

void Chat::processPendingDatagrams() {
    while(chatUdp->hasPendingDatagrams()) {

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
    return;
}

void Chat::on_exitButton_clicked() {

}
