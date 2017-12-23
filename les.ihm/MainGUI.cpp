#include "MainGUI.h"
#include "ui_MainGUI.h"


MainGUI::MainGUI(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainGUI)
{
    this->setInitParameters();
    this->setConStructs();
    this->setConnections();
}

MainGUI::~MainGUI()
{
    delete ui;
}

void MainGUI::setInitParameters(){
    ui->setupUi(this);
    this->resize(1400,800);
    this->setWindowTitle("LES Topology Auto Layout");
    this->setWindowIcon(QIcon(":/images/analysecpr.png"));

    //自定义view
    viewEc = new QGraphicsViewEc();
    ui->viewECLayout->addWidget(viewEc);//设置画布部分的布局

    //自定义scene
    //this->scene = new QGraphicsScene();
    this->scene = new QGVScene("topology", viewEc);
    this->scene->setGraphAttribute("label", "topology");
    this->scene->setGraphAttribute("splines", "ortho");
    this->scene->setGraphAttribute("rankdir", "LR");
    //this->scene->setGraphAttribute("concentrate", "true"); //Error !
    this->scene->setGraphAttribute("nodesep", "0.4");
    this->scene->setNodeAttribute("shape", "box");
    this->scene->setNodeAttribute("style", "filled");
    this->scene->setNodeAttribute("fillcolor", "white");
    this->scene->setNodeAttribute("height", "1.2");
    this->scene->setEdgeAttribute("minlen", "3");
    //this->scene->setEdgeAttribute("dir", "both");

    this->view = viewEc;
    this->view->setScene(this->scene);
    this->view->setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);
    this->view->setDragMode(QGraphicsView::ScrollHandDrag);

    //图标库

}

void MainGUI::setConStructs(){

   //添加到左侧图标控件中
    listWidget = new IconWidget();
    listWidget->setConstruct(); // 传递图标
    listWidget->setView(this->view,this->scene);
    ui->layoutIcons->addWidget(listWidget);//设置图标部分的布局
}

//信号-槽函数
void MainGUI::setConnections(){

   connect(ui->pushButton_line,SIGNAL(clicked(bool)),this,SLOT(addLine()));
   connect(ui->pushButton_polyline,SIGNAL(clicked(bool)),this,SLOT(addPolyLine()));

   connect(ui->pushButton_ok,SIGNAL(clicked(bool)),this,SLOT(okCompute()));
   connect(ui->pushButton_cancel,SIGNAL(clicked(bool)),this,SLOT(resetCompute()));

   connect(this->scene, SIGNAL(nodeContextMenu(QGVNode*)), SLOT(nodeContextMenu(QGVNode*)));
   connect(this->scene, SIGNAL(nodeDoubleClick(QGVNode*)), SLOT(nodeDoubleClick(QGVNode*)));

   connect(ui->pushButton_model2,SIGNAL(clicked(bool)),this,SLOT(openModel2()));
}

//http://blog.csdn.net/fqx111/article/details/8858503

//Qt GraphicsView框架中实现多个item之间的层次调整功能 http://blog.csdn.net/imxiangzi/article/details/50989839
void MainGUI::addPolyLine(){

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

    QGraphicsItemGroup *pGroup = new QGraphicsItemGroup();
   // pGroup->setFlags( QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    pGroup->setFlags(QGraphicsItem::ItemIsMovable);
    // 画直线，设置画笔
    QGraphicsLineItem *pItem1 = new QGraphicsLineItem();
    pItem1->setFlag(QGraphicsItem::ItemIsMovable);
    QPen pen1 = pItem1->pen();
    pen1.setColor(QColor(0, 160, 230));
    pen1.setWidth(5);
    pItem1->setPen(pen1);
    // 设置直线位于 (x1, y1) 和 (x2, y2)之间
    pItem1->setLine(QLineF(6, 5, 150, 5));

    // 画直线，设置画笔
    QGraphicsLineItem *pItem2 = new QGraphicsLineItem();
    pItem2->setFlag(QGraphicsItem::ItemIsMovable);
    QPen pen2 = pItem2->pen();
    pen2.setColor(QColor(0, 160, 230));
    pen2.setWidth(5);
    pItem2->setPen(pen2);
    // 设置直线位于 (x1, y1) 和 (x2, y2)之间
    pItem2->setLine(QLineF(6, 5, 6, 125));

    // 画直线，设置画笔
    QGraphicsLineItem *pItem3 = new QGraphicsLineItem();
    pItem3->setFlag(QGraphicsItem::ItemIsMovable);
    QPen pen3 = pItem3->pen();
    pen3.setColor(QColor(0, 160, 230));
    pen3.setWidth(5);
    pItem3->setPen(pen3);
    // 设置直线位于 (x1, y1) 和 (x2, y2)之间
    pItem3->setLine(QLineF(150, 5, 150, -125));

    pGroup->addToGroup(pItem1);
    pGroup->addToGroup(pItem2);
    pGroup->addToGroup(pItem3);

    this->scene->addItem(pGroup);
}



void MainGUI::addLine(){

    //QGraphicsItem *item  = this->scene->addLine(9, 5, 120, 55);
    //item->setFlag(QGraphicsItem::ItemIsMovable);
    // 画直线，设置画笔
    QGraphicsLineItem *pItem = new QGraphicsLineItem();
    pItem->setFlag(QGraphicsItem::ItemIsMovable);
    QPen pen = pItem->pen();
    pen.setColor(QColor(0, 160, 230));
    pen.setWidth(5);
    pItem->setPen(pen);
    // 设置直线位于 (x1, y1) 和 (x2, y2)之间
    pItem->setLine(QLineF(0, 0, 0, 100));

    this->scene->addItem(pItem);
}


void MainGUI::okCompute(){
    qDebug()<<"okCompute";

    //Add some nodes
    QGVNode *node1 = this->scene->addNode("BOX");
    node1->setIcon(QImage(":topoIcons//10700.jpg"));
    QGVNode *node2 = this->scene->addNode("SERVER0");
    node2->setIcon(QImage(":topoIcons//15200.jpg"));
    QGVNode *node3 = this->scene->addNode("SERVER1");
    node3->setIcon(QImage(":topoIcons//6700 series.jpg"));
    QGVNode *node4 = this->scene->addNode("USER");
    node4->setIcon(QImage(":topoIcons//ACS.jpg"));
    QGVNode *node5 = this->scene->addNode("SWITCH");
    node5->setIcon(QImage(":topoIcons//adm.jpg"));

    qDebug()<<this->scene->items().size();

    //Add some edges
    this->scene->addEdge(node1, node2, "TTL")->setAttribute("color", "red");
    this->scene->addEdge(node1, node2, "SERIAL");
    this->scene->addEdge(node1, node3, "RAZ")->setAttribute("color", "blue");
    this->scene->addEdge(node2, node3, "SECU");

    this->scene->addEdge(node2, node4, "STATUS")->setAttribute("color", "red");

    this->scene->addEdge(node4, node3, "ACK")->setAttribute("color", "red");

    this->scene->addEdge(node4, node2, "TBIT");
    this->scene->addEdge(node4, node2, "ETH");
    this->scene->addEdge(node4, node2, "RS232");

    this->scene->addEdge(node4, node5, "ETH1");
    this->scene->addEdge(node2, node5, "ETH2");

    QGVSubGraph *sgraph = this->scene->addSubGraph("SUB1");
    sgraph->setAttribute("label", "OFFICE");

    QGVNode *snode1 = sgraph->addNode("PC0152");
    QGVNode *snode2 = sgraph->addNode("PC0153");

    this->scene->addEdge(snode1, snode2, "RT7");

    this->scene->addEdge(node3, snode1, "GB8");
    this->scene->addEdge(node3, snode2, "TS9");

    QGVSubGraph *ssgraph = sgraph->addSubGraph("SUB2");
    ssgraph->setAttribute("label", "DESK");
    this->scene->addEdge(snode1, ssgraph->addNode("PC0155"), "S10");

    //Layout scene
    this->scene->applyLayout();
    //Fit in view
    this->view->fitInView(this->scene->sceneRect(), Qt::KeepAspectRatio);
}

void MainGUI::resetCompute(){
    qDebug()<<"resetCompute";

    //传递参数，使得图标位于画布中心位置
    this->setInitParameters();
    this->setConStructs();
    this->setConnections();
}

void MainGUI::nodeContextMenu(QGVNode *node)
{
    //Context menu exemple
    QMenu menu(node->label());

    menu.addSeparator();
    menu.addAction(tr("Informations"));
    menu.addAction(tr("Options"));

    QAction *action = menu.exec(QCursor::pos());
    if(action == 0)
        return;
}

void MainGUI::nodeDoubleClick(QGVNode *node)
{
    QPointF pos = node->pos();
    qDebug()<<"pso: "<<pos;

    QMessageBox::information(this, tr("Node double clicked"), tr("Node %1").arg(node->label()));
}

void MainGUI::openModel2(){
    QTableWidgetTp* tableTP = new QTableWidgetTp();

    tableTP->show();
}
