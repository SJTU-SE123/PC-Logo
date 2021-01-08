#ifndef TESTLOGIN_H
#define TESTLOGIN_H

#include <QObject>
#include "login.h"

class TestLogin : public QObject
{
    Q_OBJECT
public:
    explicit TestLogin(QObject *parent = nullptr);

signals:

private slots:
    void initTestCase();
    void test_case1();
    void cleanupTestCase();

private:
    Login* login;
};

#endif // TESTLOGIN_H
