#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:53:10
#
#-------------------------------------------------
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignSystem
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    person.cpp \
    entersign.cpp \
    register.cpp \
    updatepwd.cpp

HEADERS  += widget.h \
    person.h \
    entersign.h \
    register.h \
    updatepwd.h

FORMS    += widget.ui \
    person.ui \
    entersign.ui \
    register.ui \
    updatepwd.ui

RESOURCES += \
    pic/icon.qrc \
    pic/123.qrc \
    pic/tubiao.qrc

DISTFILES += \
    pic/04.jpg \
    pic/05.jpg \
    pic/06.jpg
