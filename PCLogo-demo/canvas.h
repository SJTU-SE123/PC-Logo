#ifndef STAGE_H
#define STAGE_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include "command.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    //id activate();
    void paintLine(int distance);
    void parseCommand(command* cmd);
    void setAngle(int angle);
    void paintOval(int x,int y);
    void setPos(int x,int y);

    void setPenColor(QColor c);
    void setBackground();
    void clearCanvas();
    void penUp() { this->isPenDown = false; }
    void penDown() { this->isPenDown = true; }

signals:

public slots:
    void paintEvent(QPaintEvent*) override;

private:
    QLabel *theLogo;
    qreal turtleX, turtleY;
    qreal theta;
    QList<QPair<QLineF, QColor>> lineList;
    QList<QPair<QPair<QPointF, QPoint>, QColor>> ovalList;

    QColor nextColor;
    bool isPenDown;
};

#endif // STAGE_H
