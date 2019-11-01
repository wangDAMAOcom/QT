#-------------------------------------------------
#
# Project created by QtCreator 2019-11-01T15:06:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AboutQThread
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    ProgressDialg.cpp \
    SendThread.cpp

HEADERS  += MainWindow.h \
    ProgressDialg.h \
    SendThread.h \
    GBK.h

FORMS    += MainWindow.ui \
    ProgressDialg.ui
