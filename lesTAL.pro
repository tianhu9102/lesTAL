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
               les.math \
               les.graph \


SOURCES +=  main.cpp\
            les.bean/TopologyPoint.cpp \
            les.bean/TopologyIcon.cpp \
            les.bean/TopologyLine.cpp \
            les.bean/TopologyPainter.cpp \
            les.math/Tools.cpp \
            les.math/Dispatcher.cpp \
            les.ihm/MainGUI.cpp \
   les.ihm/QGraphicsViewEc.cpp \
    les.graph/QGVCore.cpp \
    les.graph/QGVEdge.cpp \
    les.graph/QGVEdgePrivate.cpp \
    les.graph/QGVGraphPrivate.cpp \
    les.graph/QGVGvcPrivate.cpp \
    les.graph/QGVNode.cpp \
    les.graph/QGVNodePrivate.cpp \
    les.graph/QGVScene.cpp \
    les.graph/QGVSubGraph.cpp \
    les.ihm/IconWidget.cpp \
    les.ihm/IconItemGroup.cpp \
    QTableWidgetTp.cpp


HEADERS  += les.bean/TopologyPoint.h \
            les.bean/TopologyIcon.h \
            les.bean/TopologyLine.h \
            les.bean/TopologyPainter.h \
            les.math/Tools.h \
            les.math/Dispatcher.h \
            les.ihm/MainGUI.h \
    les.ihm/QGraphicsViewEc.h \
    les.graph/qgv.h \
    les.graph/QGVCore.h \
    les.graph/QGVEdge.h \
    les.graph/QGVEdgePrivate.h \
    les.graph/QGVGraphPrivate.h \
    les.graph/QGVGvcPrivate.h \
    les.graph/QGVNode.h \
    les.graph/QGVNodePrivate.h \
    les.graph/QGVScene.h \
    les.graph/QGVSubGraph.h \
    les.ihm/IconWidget.h \
    les.ihm/IconItemGroup.h \
    QTableWidgetTp.h


DISTFILES += \
            readme

FORMS += \
    MainGUI.ui \
    QTableWidgetTp.ui

INCLUDEPATH += "D:/aaEnv/Graphviz2.36/include/graphviz"
win32:LIBS += $$quote(D:\aaEnv\Graphviz2.36\lib\release\lib\gvc.lib)
win32:LIBS += $$quote(D:\aaEnv\Graphviz2.36\lib\release\lib\cgraph.lib)
win32:LIBS += $$quote(D:\aaEnv\Graphviz2.36\lib\release\lib\graph.lib)
win32:LIBS += $$quote(D:\aaEnv\Graphviz2.36\lib\release\lib\cdt.lib)
