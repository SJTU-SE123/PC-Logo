#ifndef TESTNEWLINE_H
#define TESTNEWLINE_H
#include <QtTest>
#include "newline.h"

class TestNewLine : public QObject
{
    Q_OBJECT
public:
    TestNewLine();

private slots:
    void initTestCase();
    void test_case1();
    void test_case2();
    void test_case3();
    void cleanupTestCase();

public slots:
    void receiveNewLine(QString s);

private:
    NewLine *newLine;
    QString testBuf;
};

#endif // TESTNEWLINE_H
