#ifndef TESTCHAT_H
#define TESTCHAT_H

#include <QObject>
#include <QtTest>
#include "chat.h"

class TestChat : public QObject
{
    Q_OBJECT
public:
    TestChat();
    ~TestChat();

private slots:
    void initTestCase();
    void testAppendMsg();
    void test_btn1();
    void test_btn2();
    void testSetPartner();

private:
    Chat *chat;
};

#endif // TESTCHAT_H
