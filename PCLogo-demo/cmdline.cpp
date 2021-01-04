#include "cmdline.h"

CmdLine::CmdLine(QWidget *parent) : QTextBrowser(parent)
{
    this->setFont(QFont("Helvetica"));
    this->setText(">> Command Line is Here");
    newline = new NewLine(this);
    connect(this->newline, &NewLine::sendNewLine, this, &CmdLine::receiveNewLine);
    this->setViewportMargins(0, 0, 0, LINE_HEIGHT);
}

/**
 * Reload resizeEvent for better performance after invoking setGeometry.
 */
void CmdLine::resizeEvent(QResizeEvent *event){
    QTextBrowser::resizeEvent(event);
    newline->setGeometry(0, this->height() - LINE_HEIGHT, this->width(), LINE_HEIGHT);
}

void CmdLine::receiveNewLine(QString newLine)
{
    this->append(QString(">> ").append(newLine));
    if (newLine.length() == 0) {
        return;
    }
    else emit this->sendNewLine(newLine);
}
