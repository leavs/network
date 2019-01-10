#-------------------------------------------------
#
# Project created by QtCreator 2016-10-20T20:18:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wifi
TEMPLATE = app

target.path = /usr/bin

INSTALLS += target

SOURCES += main.cpp\
        wifidialog.cpp

HEADERS  += wifidialog.h

FORMS    += wifidialog.ui
