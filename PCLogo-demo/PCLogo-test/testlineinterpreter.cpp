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

void TestLineInterpreter::testCmdTypes()
{
    QFETCH(QString, cmd);
    QFETCH(int, typ);
    LineInterpreter li;
    QCOMPARE(li.parseLine(cmd)->getType(), typ);
}

void TestLineInterpreter::testCmdTypes_data()
{
    QTest::addColumn<QString>("cmd");
    QTest::addColumn<int>("typ");

    QTest::newRow("straight move forward") << QString("FD 100\n") << static_cast<int>(STRAIGHTMOVE);
    QTest::newRow("straight move back") << QString("BK 100\n") << static_cast<int>(STRAIGHTMOVE);
    QTest::newRow("set angle right turn") << QString("RT 90\n") << static_cast<int>(SETANGLE);
    QTest::newRow("set angle left turn") << QString("LT 90\n") << static_cast<int>(SETANGLE);
    QTest::newRow("set pen color") << QString("SETPC AA55CC\n") << static_cast<int>(SETPC);
    QTest::newRow("set background color") << QString("SETBG 34EF89\n") << static_cast<int>(SETBG);
    QTest::newRow("pen up") << QString("PU\n") << static_cast<int>(PU);
    QTest::newRow("pen down") << QString("PD\n") << static_cast<int>(PD);
    QTest::newRow("clean") << QString("CLEAN\n") << static_cast<int>(CLEAN);
    QTest::newRow("reset") << QString("RESET\n") << static_cast<int>(RESET);
    QTest::newRow("stampoval") << QString("STAMPOVAL 20 18\n") << static_cast<int>(OVALMOVE);
    QTest::newRow("set position") << QString("SETXY 50 80\n") << static_cast<int>(SETXY);
    QTest::newRow("repeat") << QString("REPEAT 3 [ STAMPOVAL 10 10 ]\n") << static_cast<int>(REPEAT);
    /*
     * Procedure is a no-result command, so parser returns nullptr.
     * QTest::newRow("procedure") << QString("TO testproc x FD x END\n") << static_cast<int>(PROCEDURE);  (will cause a segfault)
     */
}

void TestLineInterpreter::testCmdParams()
{
    LineInterpreter li;
    QCOMPARE(li.parseLine("FD 100\n")->getDistance(), 100);
    QCOMPARE(li.parseLine("BK 100\n")->getDistance(), -100);
    QCOMPARE(li.parseLine("RT 90\n")->getAngle(), 90);
    QCOMPARE(li.parseLine("LT 90\n")->getAngle(), -90);
    QCOMPARE(li.parseLine("SETPC AA55CC\n")->getColor(), 0xAA55CC);
    QCOMPARE(li.parseLine("SETBG 34EF89\n")->getColor(), 0x34EF89);
    command *c1 = li.parseLine("STAMPOVAL 20 18\n");
    QCOMPARE(c1->getX(), 20);
    QCOMPARE(c1->getY(), 18);
    command *c2 = li.parseLine("SETXY 50 80\n");
    QCOMPARE(c2->getX(), 50);
    QCOMPARE(c2->getY(), 80);
    command *c3 = li.parseLine("REPEAT 3 [ FD 10 ]\n");
    QCOMPARE(c3->getTimes(), 3);
    command *c4 = c3->getContent();
    QCOMPARE(c4->getDistance(), 10);
}

void TestLineInterpreter::testNextCmd()
{
    LineInterpreter li;
    command *c = li.parseLine("FD 100\nSTAMPOVAL 40 50\n");
    QVERIFY(c->getType() == STRAIGHTMOVE);
    c = c->getNext();
    QVERIFY(c->getType() == OVALMOVE);
}

// QTEST_MAIN(test)
// #include "tst_test.moc"
