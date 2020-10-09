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
}

void Canvas::activate(){
    QPainter painter(this);
    int x = (this->geometry().width()) / 2;
    int y = (this->geometry().height()) / 2;
    theLogo = new QPixmap(":/image/littlelogo.png");
    painter.drawPixmap(x-10, y-10, 20, 20, *theLogo);
}
