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
    ../BelotusCommon/Card.cpp \
    ../BelotusCommon/Value.cpp \
    ../BelotusCommon/Suit.cpp \
    RemotePlayerAdapter.cpp
HEADERS += mainwindow.h \
    ../BelotusCommon/Player.h \
    ../BelotusCommon/Class.h \
    ../BelotusCommon/Base.h \
    ../BelotusCommon/Protocol.h \
    ../BelotusCommon/CardHolder.h \
    ../BelotusCommon/Card.h \
    ../BelotusCommon/Value.h \
    ../BelotusCommon/Suit.h \
    RemotePlayerAdapter.h
FORMS += mainwindow.ui
