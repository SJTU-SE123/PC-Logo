#include "testlogin.h"
#include <QThread>

TestLogin::TestLogin(QObject *parent) : QObject(parent)
{
    return;
}

void TestLogin::initTestCase(){
    login = new Login();
    login->show();
}

void TestLogin::test_case1(){
    QThread::sleep(1);
}

void TestLogin::cleanupTestCase(){
    login->close();
}
