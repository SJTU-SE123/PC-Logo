#include "chat.h"
#include "ui_chat.h"
#include <QToolButton>

Chat::Chat(QString username) :
    ui(new Ui::Chat) {
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 联网");
    this->setFixedSize(1200, 800);
    canvas = new Canvas(this, 560, 740);
    canvas->setGeometry(620, 20, 560, 740);
    canvas->setStyleSheet("background-color: white; border: 1px solid #555555;");
    QPalette palette;
    QPixmap pixmap(":/image/online.gif");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    canvas_opacity = new QGraphicsOpacityEffect();
    canvas->setGraphicsEffect(canvas_opacity);
    canvas_opacity->setOpacity(OPACITY);
    ui->sendButton->setStyleSheet("background-image: url(:/image/sendMessage.png);");
    ui->exitButton->setStyleSheet("background-image: url(:/image/quitNet.png);");
    ui->sendButton->setFlat(true); ui->exitButton->setFlat(true);
    this->username = username;
    lineInterpreter = new LineInterpreter();
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
    //assert(this->partner == fromUser);
    ui->textBrowser->setTextColor(Qt::red);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman", 18));
    ui->textBrowser->append("[ " + fromUser +" ] "+ time);
    ui->textBrowser->append(text);
    this->draw(text);
    update();
}

QString Chat::getText() {
    return ui->textBrowser->toPlainText();
}

void Chat::setPartner(QString fromUser) {
    if(this->partner != fromUser) {
        resetContent();
        this->partner = fromUser;
    }
}

void Chat::on_sendButton_clicked() {
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    ui->textBrowser->setTextColor(Qt::blue);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman", 18));
    ui->textBrowser->append("[ " + this->username +" ] "+ time);
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
    this->close();
}

void Chat::draw(QString str) {
    command* cmd = this->lineInterpreter->parseLine(str);
    qDebug()<<"here";
    this->canvas->parseCommand(cmd);
}

void Chat::resetContent() {
    this->ui->textBrowser->clear();
    this->ui->textEdit->clear();
    this->canvas->reset();
}

void Chat::closeEvent(QCloseEvent *event) {
    QJsonObject msg{{"toUser", this->partner}, {"status", "exit"}};
    sendMsg(msg);
    event->accept();
}

QString Chat::getPartner() {
    return this->partner;
}
