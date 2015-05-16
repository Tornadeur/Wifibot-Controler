#-------------------------------------------------
#
# Project created by QtCreator 2015-05-05T17:00:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Wifibot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    credits.cpp \
    connection.cpp \
    interface.cpp

HEADERS  += mainwindow.h \
    credits.h \
    connection.h \
    interface.h

FORMS    += mainwindow.ui \
    credits.ui \
    connection.ui \
    interface.ui

RESOURCES += \
    ressources.qrc
