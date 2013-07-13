include (../ThreadWeaver.pri)
QT       += core
QT       -= gui

TARGET = ThreadWeaverHelloWorld
CONFIG   += console
CONFIG   -= app_bundle
QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app

SOURCES += HelloWorld.cpp
