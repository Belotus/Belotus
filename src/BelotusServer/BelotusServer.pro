# -------------------------------------------------
# Project created by QtCreator 2010-11-23T21:34:24
# -------------------------------------------------
QT += network
QT -= gui
TARGET = BelotusServer
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    ../BelotusCommon/IPlayer.cpp \
    ../BelotusCommon/Class.cpp \
    ../BelotusCommon/Base.cpp \
    ../BelotusCommon/Protocol.cpp \
    ../BelotusCommon/CardHolder.cpp \
    ../BelotusCommon/Card.cpp \
    Scheduler.cpp \
    RemotePlayer.cpp \
    Dealer.cpp \
    Deck.cpp \
    CheckRules.cpp

HEADERS += ../BelotusCommon/IPlayer.h \
    ../BelotusCommon/Class.h \
    ../BelotusCommon/Base.h \
    ../BelotusCommon/Protocol.h \
    ../BelotusCommon/CardHolder.h \
    ../BelotusCommon/Card.h \
    Scheduler.h \
    RemotePlayer.h \
    Dealer.h \
    Deck.h \
    CheckRules.h
