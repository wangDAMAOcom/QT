#-------------------------------------------------
#
# Project created by QtCreator 2019-11-02T08:51:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LotterySimulation
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
		DamaoCd.cpp \
		DlgSelect.cpp \
		Source.cpp

HEADERS  += mainwindow.h \
			DamaoCd.h \
			DlgSelect.h \
			Source.h

FORMS    += mainwindow.ui \
			DlgSelect.ui
			
RESOURCES += \
	LotterySimulation.qrc
