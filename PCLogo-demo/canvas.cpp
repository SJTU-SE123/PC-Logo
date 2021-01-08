#include "canvas.h"
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <QtMath>
#include <QTime>
#include <QRgb>

Canvas::Canvas(QWidget *parent, int width, int height, bool isTwoPlayers)
    : QWidget(parent), nextColor(QColor(Qt::black)), isPenDown(true),
      defaultBgColor(Qt::GlobalColor::white),
      defaultPenColor(Qt::GlobalColor::black)
{
    this->isTwoPlayers = isTwoPlayers;
    w = width; h = height;
    turtleX = w/2;
    turtleY = h/2;
    theta = 90;
    theLogo = new QLabel(this);
    theLogo->setStyleSheet("border: 0px;");
    theLogo->setAttribute(Qt::WA_TranslucentBackground, true);
    if(isTwoPlayers) {
        turtleXP2 = w/2 + 20;
        turtleYP2 = h/2;
        thetaP2 = 90;
        theLogoP2 = new QLabel(this);
        theLogoP2->setStyleSheet("border: 0px;");
        theLogoP2->setAttribute(Qt::WA_TranslucentBackground, true);
    }
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
    if(isTwoPlayers) {
        for (auto line : lineListP2) {
            p.setPen(line.second);
            p.drawLine(line.first);
        }
        for (auto oval : ovalListP2) {
            p.setPen(oval.second);
            QPair<QPointF, QPoint> o = oval.first;
            p.drawEllipse(o.first, o.second.x(), o.second.y());
        }
        QMatrix leftmatrix;
        leftmatrix.rotate(thetaP2 - 90);
        theLogoP2->setPixmap(QPixmap(":/image/littlelogo.png").transformed(QTransform(leftmatrix),Qt::SmoothTransformation));
        theLogoP2->setGeometry(static_cast<int>(turtleXP2) - 15, static_cast<int>(turtleYP2) - 15, 30, 30);
        theLogoP2->show();
    }
}

void Canvas::paintLine(int distance, bool isP2){
    if(isP2 && isTwoPlayers) {
        qreal newTurtleX = turtleXP2 - qCos(qDegreesToRadians(thetaP2)) * distance;
        qreal newTurtleY = turtleYP2 - qSin(qDegreesToRadians(thetaP2)) * distance;
        if (this->isPenDownP2) {
            QLineF newLine(QPointF(turtleXP2, turtleYP2), QPointF(newTurtleX, newTurtleY));
            QPair<QLineF, QColor> pair(newLine, this->nextColorP2);
            lineListP2.append(pair);
        }
        turtleXP2 = newTurtleX;
        turtleYP2 = newTurtleY;
    }
    else {
        qreal newTurtleX = turtleX - qCos(qDegreesToRadians(theta)) * distance;
        qreal newTurtleY = turtleY - qSin(qDegreesToRadians(theta)) * distance;
        if (this->isPenDown) {
            QLineF newLine(QPointF(turtleX, turtleY), QPointF(newTurtleX, newTurtleY));
            QPair<QLineF, QColor> pair(newLine, this->nextColor);
            lineList.append(pair);
        }
        turtleX = newTurtleX;
        turtleY = newTurtleY;
    }
    update();
}

void Canvas::setAngle(int angle, bool isP2) {
    if(isP2 && isTwoPlayers) {
        thetaP2 += angle;
    }
    else {
        theta += angle;
    }
    update();
}

void Canvas::paintOval(int x, int y, bool isP2) {
    if(isP2 && isTwoPlayers) {
        if (this->isPenDownP2) {
            QPair<QPointF, QPoint> oval(QPointF(turtleXP2, turtleYP2), QPoint(x, y));
            QPair<QPair<QPointF, QPoint>, QColor> pair(oval, this->nextColorP2);
            ovalListP2.append(pair);
        }
    }
    else {
        if (this->isPenDown) {
            QPair<QPointF, QPoint> oval(QPointF(turtleX, turtleY), QPoint(x, y));
            QPair<QPair<QPointF, QPoint>, QColor> pair(oval, this->nextColor);
            ovalList.append(pair);
        }
    }
    update();
}

void Canvas::setPos(int x, int y, bool isP2) {
    x = x + w/2; y = h/2 - y;
    if(isP2) {
        turtleXP2 = x; turtleYP2 = y;
    }
    else {
        turtleX = x; turtleY = y;
    }
    update();
}

void Canvas::parseCommand(command *cmd, bool isP2) {
    while(cmd) {
        if (cmd->getType() == STRAIGHTMOVE) {
            paintLine(cmd->getDistance(), isP2);
        } else if (cmd->getType() == SETANGLE) {
            setAngle(cmd->getAngle(), isP2);
        } else if (cmd->getType() == OVALMOVE) {
            paintOval(cmd->getX(), cmd->getY(), isP2);
        } else if (cmd->getType() == SETXY) {
            setPos(cmd->getX(), cmd->getY(), isP2);
        } else if (cmd->getType() == REPEAT) {
            int times = cmd->getTimes();
            for (int i=0; i<times; i++) {
                parseCommand(cmd->getContent(), isP2);
            }
        } else if (cmd->getType() == PROCEDURE){
            parseCommand(cmd->getBody(), isP2);
        } else if (cmd->getType() == SETPC) {
            this->setPenColor(QColor(QRgb(cmd->getColor())), isP2);
        } else if (cmd->getType() == SETBG) {
            this->setBackground(QColor(QRgb(cmd->getColor())));
        } else if (cmd->getType() == CLEAN) {
            this->clearCanvas(isP2);
        } else if (cmd->getType() == RESET) {
            this->reset();
        } else if (cmd->getType() == PU) {
            this->penUp(isP2);
        } else if (cmd->getType() == PD) {
            this->penDown(isP2);
        }
        cmd = cmd->getNext();
    }
}

void Canvas::setPenColor(QColor c, bool isP2)
{
    if(isP2 && isTwoPlayers) {
        nextColorP2 = c;
    }
    else {
        nextColor = c;
    }
}

void Canvas::setBackground(QColor bgc)
{
    QString styleSheet("background-color: ");
    styleSheet.append(bgc.name());
    styleSheet.append(";");
    this->setStyleSheet(styleSheet);
}

void Canvas::clearCanvas(bool isP2)
{
    if(isP2 && isTwoPlayers) {
        lineListP2.clear();
        ovalListP2.clear();
        this->setBackground(this->defaultBgColor);
        this->setPenColor(this->defaultPenColor, true);
    }
    else {
        lineList.clear();
        ovalList.clear();
        this->setBackground(this->defaultBgColor);
        this->setPenColor(this->defaultPenColor);
    }
    update();
}

void Canvas::reset()
{
    if(isTwoPlayers) {
        lineListP2.clear();
        ovalListP2.clear();
        this->setPenColor(this->defaultPenColor, true);
        turtleXP2 = w/2 + 20;
        turtleYP2 = h/2;
        thetaP2 = 90;
        this->penDown(true);
    }
    lineList.clear();
    ovalList.clear();
    this->setBackground(this->defaultBgColor);
    this->setPenColor(this->defaultPenColor);
    turtleX = w/2;
    turtleY = h/2;
    theta = 90;
    this->penDown(false);
    update();
}

void Canvas::penUp(bool isP2) {
    if(isP2 && isTwoPlayers) {
        isPenDownP2 = false;
    }
    else {
        isPenDown = false;
    }
}

void Canvas::penDown(bool isP2) {
    if(isP2 && isTwoPlayers) {
        isPenDownP2 = true;
    }
    else {
        isPenDown = true;
    }
}
