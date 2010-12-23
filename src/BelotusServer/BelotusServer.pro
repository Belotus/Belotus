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
    ../BelotusCommon/Player.cpp \
    ../BelotusCommon/Class.cpp \
    ../BelotusCommon/Base.cpp \
    ../BelotusCommon/Protocol.cpp \
    ../BelotusCommon/CardHolder.cpp \
    ../BelotusCommon/Card.cpp \
    ../BelotusCommon/Suit.cpp \
    ../BelotusCommon/Value.cpp \
    Scheduler.cpp \
    RemotePlayer.cpp \
    Dealer.cpp \
    Deck.cpp \
    CheckRules.cpp \

HEADERS += \
    ../BelotusCommon/Class.h \
    ../BelotusCommon/Base.h \
    ../BelotusCommon/Protocol.h \
    ../BelotusCommon/CardHolder.h \
    ../BelotusCommon/Card.h \
    ../BelotusCommon/Suit.h \
    ../BelotusCommon/Value.h \
    ../BelotusCommon/Player.h
    Scheduler.h \
    RemotePlayer.h \
    Dealer.h \
    Deck.h \
    CheckRules.h \

