#include "chat.h"
#include "ui_chat.h"
#include <QToolButton>

Chat::Chat() :
    ui(new Ui::Chat) {
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 联网");
    canvas = new Canvas(this);
    canvas->setGeometry(420, 10, 370, 460);
    canvas->setStyleSheet("background-color: white; border: 1px solid #555555;");
    canvas->setPos(185, 230);
    this->partner = partner;
}

Chat::~Chat() {}

//ui->textBrowser->setTextColor(Qt::red);
//ui->textBrowser->setCurrentFont(QFont("Times New Roman",12));
//ui->textBrowser->append("[ " +localHostName+" ] "+ time);//与主机名聊天中
//ui->textBrowser->append(messagestr);

void Chat::sendMsg(QJsonObject msg) {
    QJsonDocument doc(msg);
    QString str(doc.toJson(QJsonDocument::Compact));
    sendMessage(str);
}

void Chat::appendMsg(QString fromUser, QString text, QString time) {
    assert(this->partner == fromUser);
    ui->textBrowser->setTextColor(Qt::red);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman",8));
    ui->textBrowser->append("[ " + this->partner +" ] "+ time);
    ui->textBrowser->append(text);
    this->draw(text);
    update();
}

void Chat::setPartner(QString fromUser) {
    this->partner = fromUser;
}

void Chat::on_sendButton_clicked() {
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->textBrowser->setTextColor(Qt::blue);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman",8));
    ui->textBrowser->append("[ " + this->partner +" ] "+ time);
    QString text = ui->textEdit->toPlainText();
    ui->textBrowser->append(text);
    QJsonObject msg{{"toUser", this->partner}, {"message", text}};
    sendMsg(msg);
    ui->textEdit->clear();
    ui->textEdit->setFocus();
    this->draw(text);
    update();
}

void Chat::on_exitButton_clicked() {

}

void Chat::draw(QString str) {
    command* cmd = this->lineInterpreter->parseLine(str);
    this->canvas->parseCommand(cmd);
}
