#include <QtTest>
#include <QCoreApplication>
#include "lineinterpreter.h"

// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_case1();

};

test::test()
{

}

test::~test()
{

}

void test::test_case1()
{
    LineInterpreter li = LineInterpreter();
    command *cm = li.parseLine(QString("FD 100\nBK 200\n"));
    QVERIFY2(cm->getType() == STRAIGHTMOVE, "check type");
    cm = cm->getNext();
    QCOMPARE(cm->getType(), STRAIGHTMOVE);
}

QTEST_MAIN(test)

#include "tst_test.moc"
