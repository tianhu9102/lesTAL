#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Dispatcher.h"

#include <QIcon>


class MainWindow : public QMainWindow
{
    Q_OBJECT


private:
    Dispatcher *disPatcher;


public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void test();

    void setInitParameters(Dispatcher *dp);
    void setInitGUI();
};

#endif // MAINWINDOW_H
