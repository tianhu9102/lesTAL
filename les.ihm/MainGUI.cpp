#include "MainGUI.h"
#include "ui_MainGUI.h"


MainGUI::MainGUI(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainGUI)
{
    ui->setupUi(this);
    //
    this->setInitParameters();
    this->setConStructs();
    this->setConnections();
}

MainGUI::~MainGUI()
{
    delete ui;
}

void MainGUI::setInitParameters(){
    this->resize(1400,800);
    this->setWindowTitle("LES Topology Auto Layout");
    this->setWindowIcon(QIcon(":/images/analysecpr.png"));

    this->view = ui->graphicsView;
    this->scene = new QGraphicsScene();
    this->view->setScene(scene);
    this->iconPath = "E:/aDownDemo/tianhuGithub/lesTAL/topoIcons";
}

void MainGUI::setConStructs(){

   //添加到左侧图标控件中
    listWidget = new MyWidget();
    listWidget->setConstruct(this->iconPath);
    ui->layoutIcons->addWidget(listWidget);
}

//信号-槽函数
void MainGUI::setConnections(){
   connect(ui->pushButton_line,SIGNAL(clicked(bool)),this,SLOT(addLine()));
   connect(ui->pushButton_polyline,SIGNAL(clicked(bool)),this,SLOT(addLine1()));
}

//http://blog.csdn.net/fqx111/article/details/8858503

//Qt GraphicsView框架中实现多个item之间的层次调整功能 http://blog.csdn.net/imxiangzi/article/details/50989839
void MainGUI::addLine(){

    //绘制直线
    //scene->addLine(13, 328, 140, 302);
    qDebug()<<"ooo";

    /*
    QString filename = this->iconPath.append("/3200 mobile access router.jpg");
    QPixmap pixmap;
    pixmap.load(filename);
    //pixmap.load(filename1);

    this->item = this->scene->addPixmap(pixmap);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setScale(1); //默认加载比例 */

    QGraphicsItem *item  = this->scene->addLine(6, 5, 150, 5);
    item->setFlag(QGraphicsItem::ItemIsMovable);

    QGraphicsItem *item1  = this->scene->addLine(6, 5, 6, 125);
    item1->setFlag(QGraphicsItem::ItemIsMovable);

    QGraphicsItem *item2  = this->scene->addLine(150, 5, 150, -125);
    item2->setFlag(QGraphicsItem::ItemIsMovable);

    this->view->setScene(scene);
}


void MainGUI::addLine1(){

    QString filename = this->iconPath.append("/3200 mobile access router.jpg");
    QPixmap pixmap;
    pixmap.load(filename);
    QGraphicsItem *item  =  scene->addPixmap(pixmap);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setScale(1);

    this->view->setScene(scene);
}
