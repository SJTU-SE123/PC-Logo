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
    testlineinterpreter.cpp \
    testlocalmode.cpp \
    testmodeselect.cpp \
    teststartwindow.cpp

INCLUDEPATH += ../

HEADERS += \
    testlineinterpreter.h \
    testlocalmode.h \
    testmodeselect.h \
    testrunner.h \
    teststartwindow.h
