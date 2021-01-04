#include "teststartwindow.h"
#include "startwindow.h"

TestStartWindow::TestStartWindow()
{
    return;
}

TestStartWindow::~TestStartWindow()
{
    return;
}

void TestStartWindow::initTestCase() {
    startWindow = new StartWindow();
    startWindow->show();
}

void TestStartWindow::test_btn1() {
    QTest::mouseMove(startWindow, QPoint(155, 280), 1000);
    QWidget *btn = startWindow->childAt(155, 280);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    }
}

void TestStartWindow::test_btn2() {
    QTest::mouseMove(startWindow, QPoint(155, 350), 1000);
    QWidget *btn = startWindow->childAt(155, 350);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    }
}

void TestStartWindow::test_btn3() {
    QTest::mouseMove(startWindow, QPoint(155, 420), 1000);
    QWidget *btn = startWindow->childAt(155, 420);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    }
}

void TestStartWindow::cleanupTestCase() {
    startWindow->close();
    qApp->closeAllWindows();
}
