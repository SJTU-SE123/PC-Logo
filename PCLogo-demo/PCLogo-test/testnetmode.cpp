#include "testnetmode.h"

TestNetMode::TestNetMode()
{

}

TestNetMode::~TestNetMode()
{

}

void TestNetMode::initTestCase() {
    this->netmode = new NetMode("test");
    this->netmode->show();
}
