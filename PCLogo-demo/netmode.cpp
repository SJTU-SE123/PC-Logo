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
    this->chat = new Chat(this->username);
    connect(chat, &Chat::sendMessage, this, &NetMode::onSendMessage);
    m_webSocket.open(QUrl(m_url));
}

void NetMode::onSendMessage(QString msg) {
    m_webSocket.sendTextMessage(msg);
}

void NetMode::paintEvent(QPaintEvent*) {
    int rowCount = ui->tableWidget->rowCount();
    for (int i=0; i<rowCount; i++) ui->tableWidget->removeRow(0);
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
    int msgCnt = jsonObject.size();
    if (msgCnt == 1){
        QJsonObject::Iterator it = jsonObject.begin();
        if (m_debug) qDebug() << "key: " << it.key() << ", value: " << it.value() << endl;

        // 客户端接受到更新在线用户列表信息
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

        // 客户端接收到用户连接请求 若当前正在和别人聊天 直接忽略。 否则弹窗。
        else if (it.key() == "fromUser") {
            if (this->partner != nullptr) return;
            QString fromUser = it.value().toString();
            QMessageBox:: StandardButton result= QMessageBox::information(this, "确认", "是否接受" + fromUser + "的连接请求",QMessageBox::Yes|QMessageBox::No);
            switch (result) {
                case QMessageBox::Yes: {
                    QJsonObject msg {{"toUser", fromUser}, {"status", "accept"}};
                    sendMsg(msg);
                    this->partner = fromUser;
                    chat->setPartner(fromUser);
                    chat->show();
                    break;
                }
                case QMessageBox::No: {
                    QJsonObject msg {{"toUser", fromUser}, {"status", "reject"}};
                    sendMsg(msg);
                    break;
                }
                default:
                    break;
            }
        } else assert(0);
    } else if (msgCnt == 2) {
        // 客户端收到对方对联机请求的回应
        QJsonObject::Iterator it = jsonObject.begin();
        assert(it.key() == "fromUser");
        QString fromUser = it.value().toString();
        it++;
        assert(it.key() == "status");
        QString status = it.value().toString();
        if (status == "accept") {
            this->partner = fromUser;
            chat->setPartner(fromUser);
            chat->show();
        }
    } else if (msgCnt == 3) {
        // 客户端之间通信，接收消息
        QJsonObject::Iterator it = jsonObject.begin();
        assert(it.key() == "fromUser");
        QString fromUser = it.value().toString();
        it++;
        assert(it.key() == "message");
        QString text = it.value().toString();
        it++;
        assert(it.key() == "timestamp");
        QString time = it.value().toString();
        if (this->partner != fromUser) return;
        this->chat->appendMsg(fromUser, text, time);
    } else assert(0);
}

void NetMode::sendMsg(QJsonObject msg) {
    QJsonDocument doc(msg);
    QString str(doc.toJson(QJsonDocument::Compact));
    m_webSocket.sendTextMessage(str);
}

void NetMode::on_tableWidget_doubleClicked(QModelIndex index) {
    QString toUser = ui->tableWidget->item(index.row(),0)->text();
    if (m_debug) qDebug() << "toUser: " << toUser << endl;
    if (toUser == this->username) return;
    QJsonObject msg {{"toUser", toUser}};
    sendMsg(msg);
}

NetMode::~NetMode() {
    delete ui;
}
