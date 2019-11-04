#-------------------------------------------------
#
# Project created by QtCreator 2019-11-04T09:04:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AboutWidget
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    CircleWidget.cpp \
    MyWidget.cpp \
    WordWidget.cpp \
    PictureWidget.cpp

HEADERS  += MainWindow.h \
    CircleWidget.h \
    MyWidget.h \
    WordWidget.h \
    GBK.h \
    PictureWidget.h

FORMS    += MainWindow.ui

RESOURCES += \
    AboutWidget.qrc
