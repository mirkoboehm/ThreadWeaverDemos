include (../ThreadWeaver.pri)
QT += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SequenceDemo
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    SequenceDemo.cpp \
    LatestUpdateRetriever.cpp \
    Parser.cpp

HEADERS  += SequenceDemo.h \
    LatestUpdateRetriever.h \
    Parser.h

FORMS    += SequenceDemo.ui
