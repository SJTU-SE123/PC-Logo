#ifndef TESTLINEINTERPRETER_H
#define TESTLINEINTERPRETER_H
#include <QtTest>
#include <QCoreApplication>

class TestLineInterpreter : public QObject
{
    Q_OBJECT

public:
    TestLineInterpreter();
    ~TestLineInterpreter() override;

private slots:
    void testCmdTypes();
    void testCmdTypes_data();
    void testCmdParams();
    void testNextCmd();
};

#endif // TESTLINEINTERPRETER_H
