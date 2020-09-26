#ifndef STAGE_H
#define STAGE_H

#include <QWidget>
#include <QPainter>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    void activate();

signals:

public slots:
    void paintEvent(QPaintEvent*) override;

private:
    QPixmap *theLogo;
};

#endif // STAGE_H
