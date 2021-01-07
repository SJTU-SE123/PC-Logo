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
    QPalette palette;
    QPixmap pixmap(":/image/netmodebkg.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
//    opacity = new QGraphicsOpacityEffect();
//    ui->tableWidget->setGraphicsEffect(opacity);
//    opacity->setOpacity(OPACITY);

    this->username = username;
    this->m_url = "ws://localhost:8080/online/" + this->username;
    this->m_debug = true;
    connect(&m_webSocket, &QWebSocket::connected, this, &NetMode::onConnected);
    connect(&m_webSocket, &QWebSocket::disconnected, this, &NetMode::closed);
    this->chat = new Chat(this->username);
    this->advChat = new AdvancedChat(this->username);
    connect(chat, &Chat::sendMessage, this, &NetMode::onSendMessage);
    connect(advChat, &AdvancedChat::sendMessage, this, &NetMode::onSendMessage);
    m_webSocket.open(QUrl(m_url));
}

void NetMode::onSendMessage(QString msg) {
    m_webSocket.sendTextMessage(msg);
}

void NetMode::paintEvent(QPaintEvent*) {
    int rowCount = ui->tableWidget->rowCount();
    for (int i=0; i<rowCount; i++) ui->tableWidget->removeRow(0);
    int size = this->userList.size();
    for (int i=0; i<size; i++) {
        QTableWidgetItem *t1 = new QTableWidgetItem(userList[i]);
        QTableWidgetItem *t2;
        if (statusList[i]) {
            t2 = new QTableWidgetItem("在线");
        } else t2 = new QTableWidgetItem("聊天中");
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,t1);
        ui->tableWidget->setItem(0,1,t2);
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
        if (m_debug) qDebug() << "key: " << it.key() << ", value: " << it.value() << Qt::endl;

        // 客户端接受到更新在线用户列表信息
        if (it.key() == "onlineUsers" || it.key() == "update") {
            QJsonArray users = it.value().toArray();
            QList<QString> usernames;
            QList<bool> statuss;
            for (QJsonArray::Iterator user = users.begin(); user != users.end(); user++) {
                QJsonObject userInfo = (*user).toObject();
                QString userName = userInfo.value("username").toString();
                bool userStatus = userInfo.value("free").toBool();
                usernames.append(userName);
                statuss.append(userStatus);
            }
            this->userList = usernames;
            this->statusList = statuss;
            update();
        }
    } else if (msgCnt == 2) {
        // 客户端收到对方对联机请求的回应
        QJsonObject::Iterator it = jsonObject.begin();
        assert(it.key() == "fromUser");
        QString fromUser = it.value().toString();
        it++;
        if (it.key() == "status") {
            QString status = it.value().toString();
            if (status == "accept") {
                this->partner = fromUser;
                if (this->type == "single") {
                    chat->setPartner(fromUser);
                    chat->show();
                } else {
                    advChat->setPartner(fromUser, false);
                    advChat->show();
                }
            } else if (status == "exit" && (!this->chat->isHidden() || !this->advChat->isHidden())) {
                QMessageBox::information(this, "通知", "对方已断开连接", QMessageBox::Yes);
                if (this->type == "single") this->chat->close();
                else if (this->type == "double") this->advChat->close();
            }
        }
        // 客户端接收到用户连接请求 若当前正在和别人聊天 直接忽略。 否则弹窗。
        else if (it.key() == "type") {
            QString type = it.value().toString();
            QString info;
            if (type == "single") info = "是否接受" + fromUser + "的双人单海龟作图邀请";
            else if (type == "double") info = "是否接受" + fromUser + "的双人双海龟作图邀请";
            QMessageBox:: StandardButton result= QMessageBox::information(this, "确认", info, QMessageBox::Yes|QMessageBox::No);
            switch (result) {
                case QMessageBox::Yes: {
                    QJsonObject msg {{"toUser", fromUser}, {"status", "accept"}};
                    sendMsg(msg);
                    this->partner = fromUser;
                    this->type = type;
                    if (this->type == "single") {
                        chat->setPartner(fromUser);
                        chat->show();
                    } else {
                        advChat->setPartner(fromUser, true);
                        advChat->show();
                    }
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
        if (this->type == "single") this->chat->appendMsg(fromUser, text, time);
        else this->advChat->appendMsg(fromUser, text, time);
    } //else assert(0);
}

void NetMode::sendMsg(QJsonObject msg) {
    QJsonDocument doc(msg);
    QString str(doc.toJson(QJsonDocument::Compact));
    m_webSocket.sendTextMessage(str);
}

void NetMode::on_tableWidget_doubleClicked(QModelIndex index) {
    QString toUser = ui->tableWidget->item(index.row(),0)->text();
    if (m_debug) qDebug() << "toUser: " << toUser << Qt::endl;
    if (toUser == this->username) return;
    QMessageBox:: StandardButton result= QMessageBox::information(this, "确认", "是否选择双人双海龟模式，默认为双人单海龟", QMessageBox::Yes|QMessageBox::No);
    switch (result) {
        // 双人双海龟
        case QMessageBox::Yes: {
            this->type = "double";
            QJsonObject msg {{"toUser", toUser}, {"type", "double"}};
            sendMsg(msg);
            break;
        }
        // 双人单海龟
        case QMessageBox::No: {
            this->type = "single";
            QJsonObject msg {{"toUser", toUser}, {"type", "single"}};
            sendMsg(msg);
            break;
        }
        default:
            break;
    }
}

NetMode::~NetMode() {
    delete ui;
}
