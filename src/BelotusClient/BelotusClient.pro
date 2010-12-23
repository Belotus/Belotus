# -------------------------------------------------
# Project created by QtCreator 2010-11-23T21:34:03
# -------------------------------------------------
QT += network
TARGET = BelotusClient
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    ../BelotusCommon/Player.cpp \
    ../BelotusCommon/Class.cpp \
    ../BelotusCommon/Base.cpp \
    ../BelotusCommon/Protocol.cpp \
    ../BelotusCommon/CardHolder.cpp \
    RemotePlayerAdapter.cpp
HEADERS += mainwindow.h \
    ../BelotusCommon/Player.h \
    ../BelotusCommon/Class.h \
    ../BelotusCommon/Base.h \
    ../BelotusCommon/Protocol.h \
    ../BelotusCommon/CardHolder.h \
    RemotePlayerAdapter.h
FORMS += mainwindow.ui
