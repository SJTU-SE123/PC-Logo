#include "cmdline.h"
#include <QDebug>

CmdLine::CmdLine(QWidget *parent): QTextBrowser(parent)
{
    this->setText(">> 这里是命令行");
    theLine = new QLineEdit(this);
    theLine->setText(">> ");
}

/**
 * 重载resizeEvent，保证在被setGeometry后有良好的表现。
 */
void CmdLine::resizeEvent(QResizeEvent *event){
    QTextBrowser::resizeEvent(event);
    theLine->setGeometry(0, this->height() - LINE_HEIGHT, this->width(), LINE_HEIGHT);
}
