#ifndef TESTSTARTWINDOW_H
#define TESTSTARTWINDOW_H
#include <QtTest>
#include "startwindow.h"

class TestStartWindow : public QObject
{
    Q_OBJECT

public:
    TestStartWindow();
    ~TestStartWindow();

private slots:
    void initTestCase();
    void test_btn1();
    void test_btn2();
    void test_btn3();
    void cleanupTestCase();

private:
    StartWindow *startWindow;
};

#endif // TESTSTARTWINDOW_H
