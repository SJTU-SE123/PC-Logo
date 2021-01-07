#ifndef TESTNETMODE_H
#define TESTNETMODE_H

#include <QObject>
#include <QtTest>
#include "netmode.h"

class TestNetMode  : public QObject
{
    Q_OBJECT
public:
    TestNetMode();
    ~TestNetMode();

private slots:
    void initTestCase();

private:
    NetMode *netmode;

};

#endif // TESTNETMODE_H
