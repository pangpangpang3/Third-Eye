#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T15:16:00
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = viewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    central/mainframe.cpp

HEADERS  += mainwindow.h \
    central/mainframe.h \
    common/constants.h \