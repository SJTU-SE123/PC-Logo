#include "canvas.h"
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <QtMath>
#include <QTime>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    turtleX = turtleY = 325;
    theta = 90;
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
    leftmatrix.rotate(theta - 90);
    theLogo->setPixmap(QPixmap(":/image/littlelogo.png").transformed(leftmatrix,Qt::SmoothTransformation));
    theLogo->setGeometry(turtleX, turtleY, 30, 30);
    theLogo->show();
}

void Canvas::paintLine(int distance){
    qreal newTurtleX = turtleX + qCos(qDegreesToRadians(theta)) * distance;
    qreal newTurtleY = turtleY - qSin(qDegreesToRadians(theta)) * distance;
    lineList.append(QLineF(QPointF(turtleX, turtleY), QPointF(newTurtleX, newTurtleY)));
    turtleX = newTurtleX;
    turtleY = newTurtleY;
    update();
}

void Canvas::setAngle(int angle) {
    theta += angle;
    update();
}

void Canvas::paintOval(int x, int y) {
    QPair<QPointF, QPoint> pair;
    pair.first = QPointF(turtleX, turtleY);
    pair.second = QPoint(x, y);
    ovalList.append(pair);
    update();
}

void Canvas::setPos(int x, int y) {
    turtleX = x; turtleY = y;
    update();
}

void Canvas::parseCommand(command *cmd) {
    while(cmd) {
        if (cmd->getType() == STRAIGHTMOVE) {
            paintLine(cmd->getDistance());
        } else if (cmd->getType() == SETANGLE) {
            setAngle(cmd->getAngle());
        } else if (cmd->getType() == OVALMOVE) {
            paintOval(cmd->getX(), cmd->getY());
        } else if (cmd->getType() == SETXY) {
            setPos(cmd->getX(), cmd->getY());
        } else if (cmd->getType() == REPEAT) {
            int times = cmd->getTimes();
            for (int i=0; i<times; i++) {
                parseCommand(cmd->getContent());
            }
        }
        cmd = cmd->getNext();
    }
}

