#ifndef MAINGUI_H
#define MAINGUI_H

#include <QMainWindow>
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QGraphicsItem>
#include <QListWidgetItem>
#include <QGraphicsView>

#include "MyWidget.h"

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

    MyWidget* listWidget;

    QGraphicsView *view;
    QGraphicsScene *scene;


    QString iconPath;

public slots:



    void addLine();
    void addLine1();

};

#endif // MAINGUI_H
