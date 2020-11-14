#include "canvas.h"
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <QtMath>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    turtleX = turtleY = 325;
    theta = 0;
    theLogo = new QLabel(this);
    theLogo->setStyleSheet("border: 0px");
    update();
}

void Canvas::paintEvent(QPaintEvent*)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    for (auto line : lineList) {
        p.drawLine(line);
    }
    for (auto oval : ovalList) {
        p.drawEllipse(oval.first, oval.second.x(), oval.second.y());
    }
    QMatrix leftmatrix;
    leftmatrix.rotate(theta);
    theLogo->setPixmap(QPixmap(":/image/littlelogo.png").transformed(leftmatrix,Qt::SmoothTransformation));
    theLogo->setGeometry(turtleX, turtleY, 30, 30);
    theLogo->show();
}

void Canvas::paintLine(int distance){
    qreal newTurtleX = turtleX + qCos(theta) * distance;
    qreal newTurtleY = turtleY + qSin(theta) * distance;
    lineList.append(QLineF(QPointF(turtleX, turtleY), QPointF(newTurtleX, newTurtleY)));
    turtleX = newTurtleX;
    turtleY = newTurtleY;
    update();
}

void Canvas::parseCommand(command *cmd) {
    while(cmd) {
        if (cmd->getType() == STRAIGHTMOVE) {
            paintLine(cmd->getDistance());
        }
        cmd = cmd->getNext();
    }
}

