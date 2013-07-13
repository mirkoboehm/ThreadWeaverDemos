TEMPLATE = app
TARGET = ImageViewer
include (../ThreadWeaver.pri)
QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += .
QT += core gui network xml widgets

!greaterThan(QT_MAJOR_VERSION, 4) {
error(This program requires Qt 5.)
}

HEADERS += ComputeThumbNailJob.h \
    FileLoaderJob.h \
    QImageLoaderJob.h \
    SMIV.h \
    SMIVItem.h \
    SMIVItemDelegate.h \
    SMIVModel.h \
    SMIVView.h
FORMS += SMIVBase.ui
SOURCES += ComputeThumbNailJob.cpp \
    FileLoaderJob.cpp \
    QImageLoaderJob.cpp \
    SMIV.cpp \
    SMIVItem.cpp \
    SMIVItemDelegate.cpp \
    SMIVModel.cpp \
    SMIVView.cpp
