#include "testnewline.h"

TestNewLine::TestNewLine()
{

}

void TestNewLine::initTestCase()
{
    this->newLine = new NewLine(nullptr);
    connect(this->newLine, &NewLine::sendNewLine, this, &TestNewLine::receiveNewLine);
    this->newLine->show();
}

void TestNewLine::test_case1()
{
    // test line inputing and sending
    QString testText("FD 100");
    QTest::keyClicks(this->newLine, testText);
    QVERIFY2(this->newLine->pureCmd() == testText, "Input mismatch");
    QTest::keyPress(this->newLine, Qt::Key::Key_Return);
    QVERIFY2(this->testBuf == testText, "Newline received and sent mismatch");
}

void TestNewLine::test_case2()
{
    // testing command history
    QList<QString> testTexts = {
        "FD 100",
        "PU",
        "FD -30",
        "PD"
    };
    for (auto & testText : testTexts) {
        QTest::keyClicks(this->newLine, testText);
        QTest::keyPress(this->newLine, Qt::Key::Key_Return);
    }
    for (int i = 0; i < testTexts.length(); ++i) {
        QTest::keyPress(this->newLine, Qt::Key::Key_Up);
        QString textShowing = this->newLine->pureCmd();
        QString testText = testTexts.at(testTexts.length() - 1 - i);
        QVERIFY2(textShowing == testText, "CommandHistory mismatch UP");
    }
    for (int i = 0; i < testTexts.length(); ++i) {
        QTest::keyPress(this->newLine, Qt::Key::Key_Down);
        QString textShowing = this->newLine->pureCmd();
        QString textShouldShowing = (i+1 >= testTexts.length()) ? ("") : (testTexts.at(i+1));
        QVERIFY2(textShowing == textShouldShowing, "CommandHistory mismatch DOWN");
    }
}

void TestNewLine::test_case3()
{
    // test cursor out of range handling
    QString testText("FD 100");
    QTest::keyClicks(this->newLine, testText);
    for (int i = 0; i < testText.length(); ++i) {
        QTest::keyPress(this->newLine, Qt::Key::Key_Left);  // move csr to the left-most of command
    }
    // test
    QList<Qt::Key> keys = { Qt::Key::Key_Left, Qt::Key::Key_Home };
    for (auto & key : keys) {
        QTest::keyPress(this->newLine, key);
        int csrPos = this->newLine->cursorPosition();
        int shouldAt = this->newLine->getLineHeadMarkLength();
        QVERIFY2(csrPos == shouldAt, "cursor out of range");
    }
}

void TestNewLine::cleanupTestCase()
{
    delete this->newLine;
}

void TestNewLine::receiveNewLine(QString s)
{
    this->testBuf = s;
}
