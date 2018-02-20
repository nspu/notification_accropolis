#-------------------------------------------------
#
# Project created by QtCreator 2017-03-18T23:45:28
#
#-------------------------------------------------

QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = notification_accropolis
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    googlefirebase.cpp

HEADERS  += mainwindow.h \
    googlefirebase.h

FORMS    += mainwindow.ui

DISTFILES += \
    .gitignore

RESOURCES += \
    icon.qrc
