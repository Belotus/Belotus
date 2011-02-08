# -------------------------------------------------
# Project created by QtCreator 2010-11-23T21:34:24
# -------------------------------------------------
QT += network
QT -= gui

DESTDIR = ../bin

TARGET = BelotusServer
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
INCLUDEPATH += ../BelotusCommon
LIBS += -L ../bin -lBelotusCommon
SOURCES +=  main.cpp \
            Scheduler.cpp \
            RemotePlayer.cpp \
            Dealer.cpp \
            Deck.cpp \
            CheckRules.cpp \
            LocalPlayer.cpp \
            NetworkFrontend.cpp

HEADERS +=  Scheduler.h \
            RemotePlayer.h \
            Dealer.h \
            Deck.h \
            CheckRules.h \
            LocalPlayer.h \
            NetworkFrontend.h
