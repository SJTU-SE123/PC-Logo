QT += testlib
QT += gui
QT += widgets
QT += multimedia
QT += websockets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

include(../PCLogo-demo.pri)

SOURCES +=  \
    main.cpp \
    testcmdline.cpp \
    testlineinterpreter.cpp \
    testlocalmode.cpp \
    testmodeselect.cpp \
    testnewline.cpp \
    teststartwindow.cpp

INCLUDEPATH += ../

HEADERS += \
    testcmdline.h \
    testlineinterpreter.h \
    testlocalmode.h \
    testmodeselect.h \
    testnewline.h \
    testrunner.h \
    teststartwindow.h
