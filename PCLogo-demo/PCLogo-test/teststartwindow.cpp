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

void TestStartWindow::test_case1()
{
    StartWindow startWindow;
    startWindow.show();

    // QTest::mouseMove(&startWindow, QPoint(160, 290), 2000);
    QWidget *btn = startWindow.childAt(160, 290);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0), 2000);
        QVERIFY2(startWindow.getNextWidget() != nullptr, "not null");
    }
}
