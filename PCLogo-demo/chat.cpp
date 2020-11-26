#include "Chat.h"
#include "ui_chat.h"
#include <QToolButton>

Chat::Chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    this->setWindowTitle("PC Logo 联网");
//    connect();
}

Chat::~Chat()
{
}
