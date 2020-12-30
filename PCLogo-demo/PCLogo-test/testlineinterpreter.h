#ifndef TESTLINEINTERPRETER_H
#define TESTLINEINTERPRETER_H
#include <QtTest>
#include <QCoreApplication>

class TestLineInterpreter : public QObject
{
    Q_OBJECT

public:
    TestLineInterpreter();
    ~TestLineInterpreter();

private slots:
    void test_case1();
    void test_case2();
};

#endif // TESTLINEINTERPRETER_H
