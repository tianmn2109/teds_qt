#-------------------------------------------------
#
# Project created by QtCreator 2015-02-05T20:36:31
#
#-------------------------------------------------

QT       += core gui

QT       += xml serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Teds
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    domparser.cpp

HEADERS  += mainwindow.h \
    domparser.h \
    teds.h

FORMS    += mainwindow.ui
