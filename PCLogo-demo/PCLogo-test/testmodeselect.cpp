#include "testmodeselect.h"
#include "modeselect.h"

TestModeSelect::TestModeSelect()
{
    return;
}

TestModeSelect::~TestModeSelect()
{
    return;
}

void TestModeSelect::initTestCase() {
    modeWindow = new ModeSelect("username");
    modeWindow->show();
}

void TestModeSelect::test_btn1() {
    QTest::mouseMove(modeWindow, QPoint(145, 260), 1000);
    QWidget *btn = modeWindow->childAt(145, 260);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    }
}

void TestModeSelect::test_btn2() {
    QTest::mouseMove(modeWindow, QPoint(145, 340), 1000);
    QWidget *btn = modeWindow->childAt(145, 340);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    }
}

void TestModeSelect::test_btn3() {
    QTest::mouseMove(modeWindow, QPoint(145, 420), 1000);
    QWidget *btn = modeWindow->childAt(145, 420);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    }
}

void TestModeSelect::cleanupTestCase() {
    modeWindow->close();
    qApp->closeAllWindows();
}
