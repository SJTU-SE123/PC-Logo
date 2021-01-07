#ifndef TESTCMDLINE_H
#define TESTCMDLINE_H
#include <QTest>
#include "cmdline.h"

#include <QObject>

class TestCmdLine : public QObject
{
    Q_OBJECT
public:
    explicit TestCmdLine(QObject *parent = nullptr);

signals:
    void sendNewLine(QString s);

public slots:
    void receiveNewLine(QString s);

private slots:
    void initTestCase();
    void test_case1();
    void cleanupTestCase();

private:
    CmdLine *cmdLine;
    QString testBuf;
};

#endif // TESTCMDLINE_H
