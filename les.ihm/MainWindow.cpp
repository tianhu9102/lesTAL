#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setInitGUI();

}

MainWindow::~MainWindow()
{

}

void MainWindow::test(){
    Dispatcher tf;
    tf.autoCompute();
}

/**
 * 传递参数：分发器Dispatcher
 * @brief MainWindow::setInitParameters
 * @param dp
 */
void MainWindow::setInitParameters(Dispatcher *dp){
    this->disPatcher = dp;
}

/**
 * 初始化界面
 * @brief MainWindow::setInitGUI
 */
void MainWindow::setInitGUI(){

    this->resize(1200,700);
    this->setWindowTitle("LES Topology Auto Layout");
    this->setWindowIcon(QIcon(":/images/analysecpr.png"));
    //this->setWindowIcon(QIcon(":/topoIcons/Service router.jpg"));

}
