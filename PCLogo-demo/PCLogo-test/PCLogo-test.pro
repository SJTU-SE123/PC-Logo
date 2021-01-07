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
    testcanvas.cpp \
    testlineinterpreter.cpp \
    testlocalmode.cpp \
    testlogin.cpp \
    testmodeselect.cpp \
    teststartwindow.cpp \
    testnetmode.cpp \
    testchat.cpp \
    testadvancedchat.cpp

INCLUDEPATH += ../

HEADERS += \
    testcanvas.h \
    testlineinterpreter.h \
    testlocalmode.h \
    testlogin.h \
    testmodeselect.h \
    testrunner.h \
    teststartwindow.h \
    testnetmode.h \
    testchat.h \
    testadvancedchat.h
