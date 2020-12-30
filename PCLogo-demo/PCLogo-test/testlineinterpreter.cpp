#include <QtTest>
#include <QCoreApplication>
#include "testlineinterpreter.h"
#include "lineinterpreter.h"

TestLineInterpreter::TestLineInterpreter()
{
    return;
}

TestLineInterpreter::~TestLineInterpreter()
{
    return;
}

void TestLineInterpreter::test_case1()
{
    LineInterpreter li = LineInterpreter();
    command *cm = li.parseLine(QString("FD 100\nBK 200\n"));
    QVERIFY2(cm->getType() == STRAIGHTMOVE, "check type");
    cm = cm->getNext();
    QCOMPARE(cm->getType(), STRAIGHTMOVE);
}

void TestLineInterpreter::test_case2()
{
    LineInterpreter li = LineInterpreter();
    command *cm = li.parseLine(QString("RT 90\nLT 90\n"));
    QVERIFY2(cm->getType() == SETANGLE, "check type");
    cm = cm->getNext();
    QCOMPARE(cm->getType(), SETANGLE);
}

// QTEST_MAIN(test)
// #include "tst_test.moc"
