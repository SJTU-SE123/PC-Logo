#ifndef TESTSTARTWINDOW_H
#define TESTSTARTWINDOW_H
#include <QtTest>

class TestStartWindow : public QObject
{
    Q_OBJECT

public:
    TestStartWindow();
    ~TestStartWindow();

private slots:
    void test_case1();
};

#endif // TESTSTARTWINDOW_H
