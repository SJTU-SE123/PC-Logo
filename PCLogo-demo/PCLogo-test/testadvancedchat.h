#ifndef TESTADVANCEDCHAT_H
#define TESTADVANCEDCHAT_H

#include <QObject>
#include <QtTest>
#include "advancedchat.h"

class TestAdvancedChat : public QObject
{
    Q_OBJECT
public:
    TestAdvancedChat();
    ~TestAdvancedChat();

private slots:
    void initTestCase();
    void testAppendMsg();
    void test_btn1();
    void test_btn2();
    void testSetPartner();

private:
    AdvancedChat *advChat;
};

#endif // TESTADVANCEDCHAT_H
