include (../ThreadWeaver.pri)
QT       += core
QT       -= gui

TARGET = ThreadWeaverHelloWorldRaw
CONFIG   += console
CONFIG   -= app_bundle
QMAKE_CXXFLAGS += -std=c++11
TEMPLATE = app

SOURCES += HelloWorldRaw.cpp
