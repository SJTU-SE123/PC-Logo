#-------------------------------------------------
#
# Project created by QtCreator 2020-09-26T09:24:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia

TARGET = PCLogo-demo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        canvas.cpp \
        codeeditor.cpp \
        connect.cpp \
        localmode.cpp \
        login.cpp \
        main.cpp \
        modeselect.cpp \
        netmode.cpp \
        register.cpp \
    speech/audio.cpp \
    speech/http.cpp \
    speech/speech.cpp \
        startwindow.cpp \
        userinfo.cpp \
    lineinterpreter.cpp \
    command.cpp

HEADERS += \
        canvas.h \
        codeeditor.h \
        connect.h \
        head.h \
        linenumberarea.h \
        localmode.h \
        login.h \
        modeselect.h \
        netmode.h \
        register.h \
    speech/audio.h \
    speech/http.h \
    speech/speech.h \
        startwindow.h \
        userinfo.h \
    lineinterpreter.h \
    command.h

FORMS += \
        connect.ui \
        localmode.ui \
        login.ui \
        modeselect.ui \
        netmode.ui \
        register.ui \
        startwindow.ui \
        userinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

RC_ICONS = logo.ico
