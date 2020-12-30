#include "newline.h"
#include <QKeyEvent>
#include <QDebug>

NewLine::NewLine(QWidget *parent)
    : QLineEdit(parent), currentCmdIndex(0), lineHeadMark(QString(">> "))
{
    this->resetLine();
}

void NewLine::resetLine()
{
    this->setText(this->lineHeadMark);
}

void NewLine::readCurrentCmd(int index)
{
    if (this->currentCmdIndex + index < 0) return;
    if (this->currentCmdIndex + index >= this->currentCmds.length())
        return;
    this->currentCmdIndex += index;
    this->setText(this->lineHeadMark
                  + QString(this->currentCmds.at(currentCmdIndex)));
}

QString NewLine::cleanText()
{
    return this->text().mid(this->lineHeadMark.length());
}

void NewLine::keyPressEvent(QKeyEvent *ke)
{
    QString cmd;
    switch (ke->key()) {
    case Qt::Key::Key_Return:
        cmd = this->cleanText();
        this->currentCmds.push_back(cmd);
        emit this->sendNewLine(cmd);
        this->resetLine();
        break;
    case Qt::Key::Key_End:
        this->setCursorPosition(this->text().length());
        break;
    case Qt::Key::Key_Home:
        this->setCursorPosition(0);
        break;
    case Qt::Key::Key_Up:
        this->readCurrentCmd(-1);
        break;
    case Qt::Key::Key_Down:
        this->readCurrentCmd(1);
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

void NewLine::mousePressEvent(QMouseEvent *)
{
    // skip
}
