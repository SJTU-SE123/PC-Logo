QT += testlib
QT += gui
QT += widgets
QT += multimedia
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

include(../PCLogo-demo.pri)

SOURCES +=  \
    main.cpp \
    testlineinterpreter.cpp

INCLUDEPATH += ../

HEADERS += \
    testlineinterpreter.h \
    testrunner.h
