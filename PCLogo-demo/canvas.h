#ifndef STAGE_H
#define STAGE_H

#include <QWidget>
#include <QPainter>
#include <QLabel>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    void activate();
    void paintExample();

signals:

public slots:
    void paintEvent(QPaintEvent*) override;

private:
    QLabel *theLogo;
//    QPixmap *theLogo;
    int x, y;
    float theta;
};

#endif // STAGE_H
