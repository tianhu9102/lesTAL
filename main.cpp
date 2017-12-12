#include "MainWindow.h"
#include <QApplication>
#include "MainGUI.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "MyWidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
   // w.show();
    w.test();

    MainGUI mainGui;
    mainGui.show();


/*
    QGraphicsScene scene;
    scene.setSceneRect(-300,-300,600,600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setCacheMode(QGraphicsView::CacheBackground);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setDragMode(QGraphicsView::ScrollHandDrag);
    view.resize(400,300);
    view.show();*/

    return a.exec();
}
