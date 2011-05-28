QT += network
QT -= gui
DESTDIR = ../bin
TEMPLATE = lib
CONFIG += staticlib
SOURCES = Base.cpp \
    Card.cpp \
    CardHolder.cpp \
    Player.cpp \
    Protocol.cpp \
    CardFactory.cpp
HEADERS = Base.h \
    Card.h \
    CardHolder.h \
    Player.h \
    Protocol.h \
    CardFactory.h \
    Types.h
