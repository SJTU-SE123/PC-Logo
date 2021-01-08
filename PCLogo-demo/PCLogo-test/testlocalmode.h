#ifndef TESTLOCALMODE_H
#define TESTLOCALMODE_H
#include <QtTest>
#include "localmode.h"

class TestLocalMode : public QObject
{
    Q_OBJECT

public:
    TestLocalMode();

private slots:
    void initTestCase();
    void test_case1();
    void cleanupTestCase();

private:
    LocalMode *localWindow;
};

#endif // TESTLOCALMODE_H
