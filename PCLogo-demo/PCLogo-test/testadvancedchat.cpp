#include "testadvancedchat.h"

TestAdvancedChat::TestAdvancedChat()
{

}

TestAdvancedChat::~TestAdvancedChat()
{

}

void TestAdvancedChat::initTestCase() {
    this->advChat = new AdvancedChat("test");
    this->advChat->show();
}

void TestAdvancedChat::testAppendMsg() {
    this->advChat->appendMsg("aaa", "bbb", "ccc");
    QString text = this->advChat->getText();
    QVERIFY(text.contains("aaa", Qt::CaseInsensitive));
    QVERIFY(text.contains("bbb", Qt::CaseInsensitive));
    QVERIFY(text.contains("ccc", Qt::CaseInsensitive));
}

void TestAdvancedChat::test_btn1() {
    QTest::mouseMove(advChat, QPoint(70, 710), 1000);
    QWidget *btn = advChat->childAt(70, 710);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    }
}

void TestAdvancedChat::test_btn2() {
    QTest::mouseMove(advChat, QPoint(430, 710), 1000);
    QWidget *btn = advChat->childAt(430, 710);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    }
}

void TestAdvancedChat::testSetPartner() {
    this->advChat->setPartner("test");
    QVERIFY(this->advChat->getPartner() == "test");
}
