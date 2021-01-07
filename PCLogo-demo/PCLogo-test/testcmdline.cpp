#include "testcmdline.h"

TestCmdLine::TestCmdLine(QObject *parent) : QObject(parent)
{

}

void TestCmdLine::initTestCase()
{
    this->cmdLine = new CmdLine(nullptr);
    connect(this, &TestCmdLine::sendNewLine, this->cmdLine, &CmdLine::receiveNewLine);
    connect(this->cmdLine, &CmdLine::sendNewLine, this, &TestCmdLine::receiveNewLine);
    this->cmdLine->show();
}

void TestCmdLine::cleanupTestCase()
{
    delete this->cmdLine;
}

void TestCmdLine::receiveNewLine(QString s)
{
    this->testBuf = s;
}

void TestCmdLine::test_case1()
{
    QString testText = "FD 100";
    emit this->sendNewLine(testText);
    QVERIFY2(this->testBuf == testText, "Send & receive failed");
}
