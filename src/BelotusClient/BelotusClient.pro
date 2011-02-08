# -------------------------------------------------
# Project created by QtCreator 2010-11-23T21:34:03
# -------------------------------------------------
QT += network

DESTDIR = ../bin

TARGET = BelotusClient
TEMPLATE = app
INCLUDEPATH += ../BelotusCommon
LIBS += -L ../bin -lBelotusCommon
SOURCES += main.cpp \
    mainwindow.cpp \
    RemotePlayerAdapter.cpp
HEADERS += mainwindow.h \
    RemotePlayerAdapter.h
FORMS += mainwindow.ui
