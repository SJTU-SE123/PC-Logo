#include "advancedchat.h"
#include "ui_advancedchat.h"

AdvancedChat::AdvancedChat(QString username) :
    ui(new Ui::AdvancedChat)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 联网");
    QPalette palette;
    QPixmap pixmap(":/image/online.gif");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    canvas1 = new Canvas(this, 430, 300);
    canvas1->setGeometry(440, 5, 430, 300);
    canvas1->setStyleSheet("background-color: white; border: 1px solid #555555;");
    this->username = username;

    canvas2 = new Canvas(this, 430, 300);
    canvas2->setGeometry(440, 310, 430, 300);
    canvas2->setStyleSheet("background-color: white; border: 1px solid #555555;");

    lineInterpreter = new LineInterpreter();
}

AdvancedChat::~AdvancedChat()
{
    delete ui;
}

void AdvancedChat::on_sendButton_clicked() {
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->textBrowser->setTextColor(Qt::blue);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman",8));
    ui->textBrowser->append("[ " + this->username +" ] "+ time);
    QString text = ui->textEdit->toPlainText();
    ui->textBrowser->append(text);
    QJsonObject msg{{"toUser", this->partner}, {"message", text}};
    sendMsg(msg);
    ui->textEdit->clear();
    ui->textEdit->setFocus();
    this->draw(true, text);
    update();
}

void AdvancedChat::on_exitButton_clicked()
{
    this->close();
}

void AdvancedChat::sendMsg(QJsonObject msg) {
    QJsonDocument doc(msg);
    QString str(doc.toJson(QJsonDocument::Compact));
    sendMessage(str);
}

void AdvancedChat::appendMsg(QString fromUser, QString text, QString time) {
    assert(this->partner == fromUser);
    ui->textBrowser->setTextColor(Qt::red);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman",8));
    ui->textBrowser->append("[ " + this->partner +" ] "+ time);
    ui->textBrowser->append(text);
    this->draw(false, text);
    update();
}

void AdvancedChat::setPartner(QString fromUser) {
    if(fromUser != this->partner) {
        resetContent();
        this->partner = fromUser;
    }
}

void AdvancedChat::draw(bool flag, QString str) {
    command* cmd = this->lineInterpreter->parseLine(str);
    if (flag) this->canvas1->parseCommand(cmd);
    else this->canvas2->parseCommand(cmd);
}

void AdvancedChat::resetContent() {
    this->ui->textBrowser->clear();
    this->ui->textEdit->clear();
    this->canvas1->reset();
    this->canvas2->reset();
}

void AdvancedChat::closeEvent(QCloseEvent *event) {
    QJsonObject msg{{"toUser", this->partner}, {"status", "exit"}};
    sendMsg(msg);
    event->accept();
}
