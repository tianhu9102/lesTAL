#ifndef MAINGUI_H
#define MAINGUI_H

#include <QMainWindow>
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QGraphicsItem>
#include <QListWidgetItem>
#include <QGraphicsView>
#include "QGraphicsViewEc.h"
#include "IconWidget.h"

#include "QGVNode.h"
#include "QGVScene.h"
#include "QGVEdge.h"
#include "QGVSubGraph.h"

#include <QGraphicsItem>
#include <QMessageBox>
#include "QTableWidgetTp.h"

using namespace std;

namespace Ui {
    class MainGUI;
}

class MainGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainGUI(QWidget *parent = 0);
    ~MainGUI();

    void setInitParameters();
    void setConStructs();
    void setConnections();

private:
    Ui::MainGUI *ui;

    IconWidget* listWidget;
    QGraphicsViewEc* view;
    QGVScene *scene;
    QGraphicsViewEc* viewEc;

public slots:
    void addPolyLine();
    void addLine();

    void okCompute();
    void resetCompute();

    void nodeContextMenu(QGVNode *node);
    void nodeDoubleClick(QGVNode *node);

    void openModel2();
};

#endif // MAINGUI_H
