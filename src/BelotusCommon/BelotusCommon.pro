QT += network
QT -= gui
DESTDIR = ../bin
TEMPLATE = lib
CONFIG += staticlib
SOURCES = Base.cpp \
    Value.cpp \
    Suit.cpp \
    Card.cpp \
    CardHolder.cpp \
    Player.cpp \
    Protocol.cpp \
    CardFactory.cpp
HEADERS = Base.h \
    Value.h \
    Suit.h \
    Card.h \
    CardHolder.h \
    Player.h \
    Protocol.h \
    CardFactory.h
