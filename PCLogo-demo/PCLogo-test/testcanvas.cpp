#include "testcanvas.h"
#include "lineinterpreter.h"
#include "command.h"
#include <QThread>

TestCanvas::TestCanvas(QObject *parent) : QObject(parent)
{
    return;
}

void TestCanvas::initTestCase(){
    canvas = new Canvas(nullptr, 720, 720);
    canvas->setFixedSize(720, 720);
    canvas->show();
}

void TestCanvas::test_case1(){
    LineInterpreter interpreter;
    command* cmd = interpreter.parseLine("FD 100");
    canvas->parseCommand(cmd);
//    QThread::sleep(1);
}

void TestCanvas::cleanupTestCase(){
    canvas->close();
}
