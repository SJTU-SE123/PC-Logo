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

signals:

public slots:
    void paintEvent(QPaintEvent*) override;

private:
    QLabel *theLogo;
    qreal turtleX, turtleY;
    qreal theta;
    QList<QLineF> lineList;
    QList<QPair<QPointF, QPoint>> ovalList;
};

#endif // STAGE_H
