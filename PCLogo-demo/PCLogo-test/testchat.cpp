#include "testchat.h"

TestChat::TestChat()
{

}

TestChat::~TestChat()
{

}

void TestChat::initTestCase() {
    this->chat = new Chat("test");
    this->chat->show();
}

void TestChat::testAppendMsg() {
    this->chat->appendMsg("aaa", "bbb", "ccc");
    QString text = this->chat->getText();
    QVERIFY(text.contains("aaa", Qt::CaseInsensitive));
    QVERIFY(text.contains("bbb", Qt::CaseInsensitive));
    QVERIFY(text.contains("ccc", Qt::CaseInsensitive));
}

void TestChat::test_btn1() {
    QTest::mouseMove(chat, QPoint(70, 710), 1000);
    QWidget *btn = chat->childAt(70, 710);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    }
}

void TestChat::test_btn2() {
    QTest::mouseMove(chat, QPoint(430, 710), 1000);
    QWidget *btn = chat->childAt(430, 710);
    if(btn) {
        QTest::mouseClick(btn, Qt::LeftButton, Qt::NoModifier, QPoint(0, 0));
    }
}

void TestChat::testSetPartner() {
    this->chat->setPartner("test");
    QVERIFY(this->chat->getPartner() == "test");
}
