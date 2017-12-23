#include <QApplication>
#include "MainGUI.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "IconWidget.h"
#include "Dispatcher.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableWidgetTp* tableTP = new QTableWidgetTp();
    tableTP->show();

    //MainGUI mainGui;
    //mainGui.show();
/*
    Dispatcher dfs;
    dfs.autoCompute();*/

    /*
    MainWindow w;
    w.show();
    w.drawGraph();

    MainGUI mainGui;
    mainGui.show();

    Dispatcher dfs;
    dfs.autoCompute();*/


    return a.exec();
}
