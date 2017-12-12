#-------------------------------------------------
#
# Project created by QtCreator 2017-12-05T19:42:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lesTAL
TEMPLATE = app


RESOURCES = \
    images.qrc \
    icon.qrc



INCLUDEPATH += les.bean \
               les.ihm \
               les.math

SOURCES +=  main.cpp\
            les.ihm/MainWindow.cpp \
            les.bean/TopologyPoint.cpp \
            les.bean/TopologyIcon.cpp \
            les.bean/TopologyLine.cpp \
            les.bean/TopologyPainter.cpp \
            les.math/Tools.cpp \
            les.math/Dispatcher.cpp \
            les.ihm/MainGUI.cpp \
            les.ihm/MyWidget.cpp

HEADERS  += les.ihm/MainWindow.h \
            les.bean/TopologyPoint.h \
            les.bean/TopologyIcon.h \
            les.bean/TopologyLine.h \
            les.bean/TopologyPainter.h \
            les.math/Tools.h \
            les.math/Dispatcher.h \
            les.ihm/MainGUI.h \
            les.ihm/MyWidget.h

DISTFILES += \
            readme

FORMS += \
    MainGUI.ui
