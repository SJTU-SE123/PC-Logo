#ifndef TESTCANVAS_H
#define TESTCANVAS_H

#include <QObject>
#include "canvas.h"

class TestCanvas : public QObject
{
    Q_OBJECT
public:
    explicit TestCanvas(QObject *parent = nullptr);

signals:

private slots:
    void initTestCase();
    void test_case1();
    void cleanupTestCase();

private:
    Canvas *canvas;
};

#endif // TESTCANVAS_H
