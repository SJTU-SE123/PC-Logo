#include "advancedchat.h"
#include "ui_advancedchat.h"

AdvancedChat::AdvancedChat(QString username) :
    ui(new Ui::AdvancedChat)
{
    ui->setupUi(this);
    QPalette palette;
    QPixmap pixmap(":/image/online.gif");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    this->setWindowTitle("PC Logo 联网");
    canvas = new Canvas(this, 560, 740, true);
    canvas->setGeometry(620, 20, 560, 740);
    canvas->setStyleSheet("background-color: white; border: 1px solid #555555;");
    this->username = username;
    canvas_opacity = new QGraphicsOpacityEffect();
    canvas->setGraphicsEffect(canvas_opacity);
    canvas_opacity->setOpacity(OPACITY);
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
    this->draw(isP2, text);
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
    this->draw(!isP2, text);
    update();
}

void AdvancedChat::setPartner(QString fromUser, bool isP2) {
    if(fromUser != this->partner) {
        resetContent();
        this->partner = fromUser;
        this->isP2 = isP2;
    }
}

void AdvancedChat::draw(bool flag, QString str) {
    qDebug() << "isP2: " << flag;
    command* cmd = this->lineInterpreter->parseLine(str);
    this->canvas->parseCommand(cmd, flag);
}

void AdvancedChat::resetContent() {
    this->ui->textBrowser->clear();
    this->ui->textEdit->clear();
    this->canvas->reset();
}

void AdvancedChat::closeEvent(QCloseEvent *event) {
    QJsonObject msg{{"toUser", this->partner}, {"status", "exit"}};
    sendMsg(msg);
    event->accept();
}
