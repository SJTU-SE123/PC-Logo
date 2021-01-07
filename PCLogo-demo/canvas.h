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
    explicit Canvas(QWidget *parent = nullptr, int width = 720, int height = 720,
                    bool isTwoPlayer = false);
    //id activate();
    void paintLine(int distance, bool isP2 = false);
    void parseCommand(command* cmd, bool isP2 = false);
    void setAngle(int angle, bool isP2 = false);
    void paintOval(int x,int y, bool isP2 = false);
    void setPos(int x,int y, bool isP2 = false);
    void setPenColor(QColor c, bool isP2 = false);
    void setBackground(QColor bgc);
    void clearCanvas(bool isP2 = false);
    void reset();
    void penUp(bool isP2 = false);
    void penDown(bool isP2 = false);

signals:

public slots:
    void paintEvent(QPaintEvent*) override;

private:
    bool isTwoPlayers;
    QLabel *theLogo, *theLogoP2;
    qreal turtleX, turtleY, turtleXP2, turtleYP2;
    qreal theta, thetaP2;
    QList<QPair<QLineF, QColor>> lineList, lineListP2;
    QList<QPair<QPair<QPointF, QPoint>, QColor>> ovalList, ovalListP2;

    QColor nextColor, nextColorP2;
    bool isPenDown, isPenDownP2;

    QColor defaultBgColor;
    QColor defaultPenColor;

    int w;
    int h;
};

#endif // STAGE_H
