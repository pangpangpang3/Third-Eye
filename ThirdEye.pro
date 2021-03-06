#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T15:16:00
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ThirdEye
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    central/mainframe.cpp \
    central/imagewidget.cpp \
    exif/exifutil.cpp \
    imageinfowidget.cpp

HEADERS  += mainwindow.h \
    central/mainframe.h \
    common/constants.h \
    central/imagewidget.h \
    exif/exifutil.h \
    side/imageinfowidget.h
CONFIG += c++11 link_pkgconfig
PKGCONFIG += libexif
