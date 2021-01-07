#include "testrunner.h"
#include "testlineinterpreter.h"
#include "teststartwindow.h"
#include "testmodeselect.h"
#include "testlocalmode.h"
#include "testnewline.h"
#include "testcmdline.h"

int main(int argc, char *argv[])
{
    TestRunner tr;
    tr.addTest(new TestLineInterpreter);
    tr.addTest(new TestStartWindow);
    tr.addTest(new TestModeSelect);
    tr.addTest(new TestLocalMode);
    tr.addTest(new TestNewLine);
    tr.addTest(new TestCmdLine);

    bool pass = tr.runTests(argc, argv);
    qDebug() << "Overall result: " << (pass ? "PASS" : "FAIL");

    return pass ? 0 : 1;
}
