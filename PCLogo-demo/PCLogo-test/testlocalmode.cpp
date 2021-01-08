#include "testlocalmode.h"

TestLocalMode::TestLocalMode()
{
    return;
}

void TestLocalMode::initTestCase() {
    localWindow = new LocalMode();
    localWindow->show();
}

void TestLocalMode::test_case1() {
    QTest::mouseMove(localWindow, QPoint(1030, 35), 1000);
    QWidget *btn = localWindow->childAt(1030, 35);
    if(btn) QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    QTest::mouseMove(localWindow, QPoint(900, 35), 1000);
    btn = localWindow->childAt(900, 35);
    if(btn) QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    QTest::mouseMove(localWindow, QPoint(770, 35), 1000);
    btn = localWindow->childAt(770, 35);
//    if(btn) QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
}

void TestLocalMode::cleanupTestCase() {
    localWindow->close();
}
