#include "canvas.h"
#include <QPainter>
#include <QStyleOption>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
}

void Canvas::paintEvent(QPaintEvent*)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    activate();
    paintExample();
}

void Canvas::activate(){
    x = (this->geometry().width()) / 2;
    y = (this->geometry().height()) / 2;
    theta = 0;
    theLogo = new QLabel(this);
    theLogo->setPixmap(QPixmap(":/image/littlelogo.png"));
    theLogo->setGeometry(x-15, y-15, 30, 30);
    theLogo->setStyleSheet("border: 0px");
//    theLogo->setAttribute(Qt::WA_Tran slucentBackground);
    theLogo->show();
}

void Canvas::paintExample(){
//    QPainter painter(this);
//    painter.setPen(QPen(Qt::black, 1));
//    painter.drawLine(x, y, x, y-50);
//    y -= 50;
//    update();
//    theLogo->setGeometry(x-15, y-15, 30, 30);

//    QPainter painter(this);
//    theLogo = new QPixmap(":/image/littlelogo.png");
//    painter.drawPixmap(x-16, y-16, 32, 32, *theLogo);
}
