#ifndef TESTMODESELECT_H
#define TESTMODESELECT_H
#include <QtTest>
#include "modeselect.h"

class TestModeSelect : public QObject
{
    Q_OBJECT

public:
    TestModeSelect();
    ~TestModeSelect();

private slots:
    void initTestCase();
    void test_btn1();
    void test_btn2();
    void test_btn3();
    void cleanupTestCase();

private:
    ModeSelect *modeWindow;
};
#endif // TESTMODESELECT_H
