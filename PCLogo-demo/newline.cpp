#include "newline.h"
#include <QKeyEvent>
#include <QDebug>

NewLine::NewLine(QWidget *parent)
    : QLineEdit(parent), currentCmdIndex(0), lineHeadMark(QString(">> "))
{
    this->resetLine();
    this->cmdHistory.append("");
}

void NewLine::resetLine()
{
    this->setText(this->lineHeadMark);
}

void NewLine::readCurrentCmd()
{
    this->setText(this->lineHeadMark + this->cmdHistory.at(currentCmdIndex));
}

void NewLine::writeCurrentCmd()
{
    QString cmd = this->pureCmd();
    this->cmdHistory[this->currentCmdIndex] = cmd;
}

void NewLine::switchCurrentCmd(SwitchType st)
{
    if (st == REVERSE) {
        if (this->currentCmdIndex - 1 < 0) return;
        this->writeCurrentCmd();
        this->currentCmdIndex -= 1;
        this->readCurrentCmd();
    }
    else if (st == FORWARD) {
        if (this->currentCmdIndex + 1 >= this->cmdHistory.length()) return;
        this->writeCurrentCmd();
        this->currentCmdIndex += 1;
        this->readCurrentCmd();
    }
}

QString NewLine::pureCmd()
{
    return this->text().mid(this->lineHeadMark.length());
}

void NewLine::handleReturn() {
    this->writeCurrentCmd();
    emit this->sendNewLine(this->pureCmd());
    this->cmdHistory.append("");
    this->currentCmdIndex = this->cmdHistory.length() - 1;
    this->resetLine();
}

void NewLine::keyPressEvent(QKeyEvent *ke)
{
    switch (ke->key()) {
    case Qt::Key::Key_Return:
        this->handleReturn();
        break;
    case Qt::Key::Key_End:
        this->setCursorPosition(this->text().length());
        break;
    case Qt::Key::Key_Home:
        this->setCursorPosition(this->lineHeadMark.length());
        break;
    case Qt::Key::Key_Up:
        this->switchCurrentCmd(REVERSE);
        break;
    case Qt::Key::Key_Down:
        this->switchCurrentCmd(FORWARD);
        break;
    case Qt::Key::Key_Left:
    case Qt::Key::Key_Backspace:
    case Qt::Key::Key_Delete:
        if (this->cursorPosition() <= this->lineHeadMark.length())
            this->setCursorPosition(this->lineHeadMark.length());
        else QLineEdit::keyPressEvent(ke);
        break;
    default:
        QLineEdit::keyPressEvent(ke);
    }
}
