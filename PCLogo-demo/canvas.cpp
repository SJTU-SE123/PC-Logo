#include "canvas.h"
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <QtMath>
#include <QTime>
#include <QRgb>

Canvas::Canvas(QWidget *parent) : QWidget(parent), nextColor(QColor(Qt::black))
{
    turtleX = 360;
    turtleY = 360;
    theta = 90;
    theLogo = new QLabel(this);
    theLogo->setStyleSheet("border: 0px;");
    theLogo->setAttribute(Qt::WA_TranslucentBackground, true);
    update();
}

void Canvas::paintEvent(QPaintEvent*)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    for (auto line : lineList) {
        p.setPen(line.second);
        p.drawLine(line.first);
    }
    for (auto oval : ovalList) {
        p.setPen(oval.second);
        QPair<QPointF, QPoint> o = oval.first;
        p.drawEllipse(o.first, o.second.x(), o.second.y());
    }
    QMatrix leftmatrix;
    leftmatrix.rotate(theta - 90);
    theLogo->setPixmap(QPixmap(":/image/littlelogo.png").transformed(QTransform(leftmatrix),Qt::SmoothTransformation));
    theLogo->setGeometry(static_cast<int>(turtleX) - 15, static_cast<int>(turtleY) - 15, 30, 30);
    theLogo->show();
}

void Canvas::paintLine(int distance){
    qreal newTurtleX = turtleX - qCos(qDegreesToRadians(theta)) * distance; //zzy:我不知道为什么是减，但是它画对了
    qreal newTurtleY = turtleY - qSin(qDegreesToRadians(theta)) * distance;
    if (this->isPenDown) {
        QLineF newLine(QPointF(turtleX, turtleY), QPointF(newTurtleX, newTurtleY));
        QPair<QLineF, QColor> pair(newLine, this->nextColor);
        lineList.append(pair);
    }
    turtleX = newTurtleX;
    turtleY = newTurtleY;
    update();
}

void Canvas::setAngle(int angle) {
    theta += angle;
    update();
}

void Canvas::paintOval(int x, int y) {
    if (this->isPenDown) {
        QPair<QPointF, QPoint> oval(QPointF(turtleX, turtleY), QPoint(x, y));
        QPair<QPair<QPointF, QPoint>, QColor> pair(oval, this->nextColor);
        ovalList.append(pair);
    }
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
        } else if (cmd->getType() == PROCEDURE){
            parseCommand(cmd->getBody());
        } else if (cmd->getType() == SETPC) {
            this->setPenColor(QColor(QRgb(cmd->getColor())));
        } else if (cmd->getType() == SETBG) {
            QString styleSheet("background-color: ");
            styleSheet.append(QColor(QRgb(cmd->getColor())).name());
            styleSheet.append(";");
            this->setStyleSheet(styleSheet);
        } else if (cmd->getType() == CLEAN) {
            this->clearCanvas();
        } else if (cmd->getType() == PU) {
            this->penUp();
        } else if (cmd->getType() == PD) {
            this->penDown();
        }
        cmd = cmd->getNext();
    }
}

void Canvas::setPenColor(QColor c)
{
    this->nextColor = c;
}

void Canvas::clearCanvas()
{
    this->lineList.clear();
    this->ovalList.clear();
    update();
}
