#include "QTableWidgetTp.h"
#include "ui_QTableWidgetTp.h"

QTableWidgetTp::QTableWidgetTp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTableWidgetTp)
{
    ui->setupUi(this);

    this->setInitParameters();

    connect(ui->pushButton_addIcon,SIGNAL(clicked(bool)),this,SLOT(addIconF()));
    connect(ui->pushButton_addLine,SIGNAL(clicked(bool)),this,SLOT(addLineF()));
    connect(ui->pushButton_ok,SIGNAL(clicked(bool)),this,SLOT(autoLayout()));
}

QTableWidgetTp::~QTableWidgetTp()
{
    delete ui;
}

void QTableWidgetTp::setInitParameters(){
    //初始化图库
    listTIcons = tools.getDatabaseIcons();
    tPainter.setInitParameters(listTIcons);

    ui->tableWidget_Icon->setColumnCount(5);
    QStringList headers;
    headers << "iconId" <<" Icon"<< "type"<< "W" << "H" ;
    ui->tableWidget_Icon->setHorizontalHeaderLabels(headers);

    ui->tableWidget_Line->setColumnCount(3);
    QStringList headers_line;
    headers_line << "lineId"<< "start" <<" end";
    ui->tableWidget_Line->setHorizontalHeaderLabels(headers_line);


    //图标库
    list<TopologyIcon *>::iterator testiterator;
    for (testiterator = listTIcons.begin(); testiterator != listTIcons.end(); ++testiterator)
    {
        //根据图标type获取对应的icon
        TopologyIcon *kk = *testiterator;
        QPixmap pixmap(QString::fromStdString(kk->getIconPath()));
        pixmap.scaled(2, Qt::KeepAspectRatio);
        QIcon yy( pixmap);

        //添加图库类型
        ui->comboBox_iconTpye->addItem(yy,QString::number(kk->type(), 10) );

        //初始化设置每个图库长宽属性.......
        tPainter.setIconType(kk->type(),40,30);
    }

      ui->comboBox_iconTpye->setStyleSheet("QComboBox{border:1px solid gray;}"
      "QComboBox QAbstractItemView::item{height:60px;}" //下拉选项高度
      "QComboBox::down-arrow{image:url(:/images/download.png);}" //下拉箭头
      "QComboBox::drop-down{border:0px;}"); //下拉按钮

    ui->lineEdit_width->setText("40");
    ui->lineEdit_height->setText("30");
}

void QTableWidgetTp::addIconF(){

    QString p2,p3,p4;
    p2=ui->comboBox_iconTpye->currentText().trimmed();
    p3=ui->lineEdit_width->text().trimmed();
    p4=ui->lineEdit_height->text().trimmed();

    if(p2==NULL|p3==NULL|p4==NULL){

    }else{
        int RowCont;
        RowCont = ui->tableWidget_Icon->rowCount();
        qDebug()<<"j "<<RowCont ;
        ui->tableWidget_Icon->insertRow(RowCont);//增加一行

        //功能： 插入元素
        ui->tableWidget_Icon->setItem(RowCont,2,new QTableWidgetItem(p2));
        ui->tableWidget_Icon->setItem(RowCont,3,new QTableWidgetItem(p3));
        ui->tableWidget_Icon->setItem(RowCont,4,new QTableWidgetItem(p4));

        //算法： 添加和分配图标id
        tPainter.setIconType(p2.toInt(),p3.toInt(),p4.toInt());
        int iconID= tPainter.addIcon(p2.toInt());
        string fullname = tPainter.getFullIconName();

        ui->tableWidget_Icon->setItem(RowCont,0,new QTableWidgetItem(QString::number(iconID,10)));
        ui->tableWidget_Icon->setItem(RowCont,1,new QTableWidgetItem(QIcon(QString::fromStdString(fullname))," "));

        //联动添加
        ui->comboBox_nodeS->addItem(QString::number(iconID,10));
        ui->comboBox_nodeE->addItem(QString::number(iconID,10));
    }

}

void QTableWidgetTp::addLineF(){
    QString p2,p3;
    p2=ui->comboBox_nodeS->currentText().trimmed();
    p3=ui->comboBox_nodeE->currentText().trimmed();

    if(p2==NULL|p3==NULL){

    }else{
        int RowCont;
        RowCont = ui->tableWidget_Line->rowCount();
        qDebug()<<"j "<<RowCont ;
        ui->tableWidget_Line->insertRow(RowCont);//增加一行

        //功能： 插入元素
        ui->tableWidget_Line->setItem(RowCont,1,new QTableWidgetItem(p2));
        ui->tableWidget_Line->setItem(RowCont,2,new QTableWidgetItem(p3));

        //算法： 分配线段id
        int lineId = tPainter.addLine(TopologyPainter::Line,p2.toInt(),p3.toInt());
        ui->tableWidget_Line->setItem(RowCont,0,new QTableWidgetItem(QString::number(lineId,10)));
    }
}


void QTableWidgetTp::autoLayout(){

    view = new QGraphicsViewEc();
    scene = new QGVScene("topology", view);
    view->setScene(scene);

    QWidget* widget = new QWidget();
    widget->resize(1000,800);
    QHBoxLayout* hBoxLayout = new QHBoxLayout(widget);
    hBoxLayout->addWidget(view);//设置画布部分的布局

    scene->setGraphAttribute("splines", "ortho");
    scene->setGraphAttribute("rankdir", "LR");
    scene->setGraphAttribute("nodesep", "0.4");
    scene->setNodeAttribute("shape", "box");
    scene->setNodeAttribute("style", "filled");
    scene->setNodeAttribute("fillcolor", "white");
    scene->setNodeAttribute("height", "1.2");
    scene->setEdgeAttribute("minlen", "3");
    widget->show();

    //-----------------------------------------------
    //  开始布局
    //-----------------------------------------------
    tPainter.printIcons();
    tPainter.printLines();

    //Add some nodes
    QGVNode *node1 = scene->addNode("BOX");
    node1->setIcon(QImage(":/topoIcons/Gnome-System-Run-64.png"));
    QGVNode *node2 = scene->addNode("SERVER0");
    node2->setIcon(QImage(":/topoIcons/Gnome-Network-Transmit-64.png"));
    QGVNode *node3 = scene->addNode("SERVER1");
    node3->setIcon(QImage(":/topoIcons/Gnome-Network-Transmit-64.png"));
    QGVNode *node4 = scene->addNode("USER");
    node4->setIcon(QImage(":/topoIcons/Gnome-Stock-Person-64.png"));
    QGVNode *node5 = scene->addNode("SWITCH");
    node5->setIcon(QImage(":/topoIcons/Gnome-Network-Server-64.png"));

    QGVNode *node6 = scene->addNode("LesRouter6");
    node6->setIcon(QImage(":/topoIcons/15200.jpg"));
    QGVNode *node7 = scene->addNode("LesRouter7");
    node7->setIcon(QImage(":/topoIcons/10700.jpg"));
    QGVNode *node8 = scene->addNode("LesRouter8");
    node8->setIcon(QImage(":/topoIcons/ace.jpg"));
    QGVNode *node9 = scene->addNode("LesRouter9");
    node9->setIcon(QImage(":/topoIcons/atm 3800.jpg"));
    QGVNode *node10 = scene->addNode("LesRouter10");
    node10->setIcon(QImage(":/topoIcons/10700.jpg"));
    QGVNode *node11 = scene->addNode("LesRouter11");
    node11->setIcon(QImage(":/topoIcons/15200.jpg"));
    QGVNode *node12 = scene->addNode("LesRouter12");
    node12->setIcon(QImage(":/topoIcons/10700.jpg"));
    QGVNode *node13 = scene->addNode("LesRouter13");
    node13->setIcon(QImage(":/topoIcons/ace.jpg"));
    QGVNode *node14 = scene->addNode("LesRouter14");
    node14->setIcon(QImage(":/topoIcons/atm 3800.jpg"));
    //QGVNode *node15 = scene->addNode("LesRouter5");
    //node15->setIcon(QImage(":/icons/10700.jpg"));

    //
    scene->addEdge(node1, node6, "test");
    scene->addEdge(node1, node7, "test");
    scene->addEdge(node1, node8, "test");
    scene->addEdge(node1, node9, "test");
    scene->addEdge(node1, node10, "test");

    scene->addEdge(node2, node11, "test1")->setAttribute("color","green");
    scene->addEdge(node2, node12, "test1")->setAttribute("color","red");
    scene->addEdge(node3, node13, "test1");
    scene->addEdge(node3, node14, "test1");

    //Add some edges
    scene->addEdge(node1, node2, "TTL")->setAttribute("color", "red");
    scene->addEdge(node1, node2, "SERIAL");
    scene->addEdge(node1, node3, "RAZ")->setAttribute("color", "blue");
    scene->addEdge(node2, node3, "SECU");

    scene->addEdge(node2, node4, "STATUS")->setAttribute("color", "red");

    scene->addEdge(node4, node3, "ACK")->setAttribute("color", "red");

    scene->addEdge(node4, node2, "TBIT");
    scene->addEdge(node4, node2, "ETH");
    scene->addEdge(node4, node2, "RS232");

    scene->addEdge(node4, node5, "ETH1");
    scene->addEdge(node2, node5, "ETH2");


    QGVSubGraph *sgraph = scene->addSubGraph("SUB1");
    sgraph->setAttribute("label", "OFFICE");

    QGVNode *snode1 = sgraph->addNode("PC0152");
    QGVNode *snode2 = sgraph->addNode("PC0153");

    scene->addEdge(snode1, snode2, "RT7");

    scene->addEdge(node3, snode1, "GB8");
    scene->addEdge(node3, snode2, "TS9");

    QGVSubGraph *ssgraph = sgraph->addSubGraph("SUB2");
    ssgraph->setAttribute("label", "DESK");
    scene->addEdge(snode1, ssgraph->addNode("PC0155"), "S10");

    //Layout scene
    scene->applyLayout();
    //Fit in view
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}
