QT += testlib
QT += gui
QT += widgets
QT += multimedia
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

include(../PCLogo-demo.pri)

SOURCES +=  tst_test.cpp

INCLUDEPATH += ../