#include "testrunner.h"
#include "testlineinterpreter.h"
#include "teststartwindow.h"

int main(int argc, char *argv[])
{
    TestRunner tr;
    tr.addTest(new TestLineInterpreter);
    tr.addTest(new TestStartWindow);

    bool pass = tr.runTests(argc, argv);
    qDebug() << "Overall result: " << (pass ? "PASS" : "FAIL");

    return pass ? 0 : 1;
}
