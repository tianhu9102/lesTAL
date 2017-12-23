#include "IconItemGroup.h"

IconItemGroup::IconItemGroup(QGraphicsItemGroup *parent)
{

}

IconItemGroup* IconItemGroup::getIconTextItems(QGVScene *_scene,  QString picName, int tmp){
    this->scene = _scene;

    IconItemGroup *pGroup = new IconItemGroup();
    //pGroup->setFlags( QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    pGroup->setFlags( QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    QPixmap pix(picName);
    QGraphicsItem *displayItem  = _scene->addPixmap(pix);


    //qDebug()<<pix.size();
    //显示文字
    QGraphicsTextItem* txtItem = new QGraphicsTextItem();
    txtItem->setPlainText("name: \n"+picName.split("/")[1].split(".")[0]);//显示文字
    txtItem->setTextInteractionFlags(Qt::TextEditorInteraction);//可编辑
    //connect(txtItem->document(), &QTextDocument::contentsChanged, [=]() { txtItem->toPlainText()});

    QFont font = txtItem->font();
    font.setPixelSize(14);  // 像素大小
    font.setItalic(true);  // 斜体
    //font.setUnderline(true);  // 下划线
    txtItem->setFont(font);

    pGroup->addToGroup(displayItem);
    pGroup->addToGroup(txtItem);
    pGroup->setPos(tmp,0);
    pGroup->setFlag(QGraphicsItem::ItemIsMovable);
    pGroup->setFlag(QGraphicsItem::ItemIsSelectable);


    return pGroup;
}

//鼠标按下事件处理函数
void IconItemGroup::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug("************IconItemGroup::mousePressEvent*****************");
    //setFocus();

    //判断右键事件
    if(mouseEvent->button()==Qt::RightButton){
        QMenu menu;
        QAction *addLineAction = menu.addAction("add Line");
        QAction *addPolyLineAction = menu.addAction("add PolyLine");
        QAction *deleteAction = menu.addAction("delete Icon");
        QAction *selectedAction = menu.exec(mouseEvent->screenPos());

        if(selectedAction == addLineAction){
            qDebug()<<mouseEvent->pos();
            //qDebug()<<mouseEvent->pos().rx()<<", "<<mouseEvent->pos().ry();

            //画直线
            QGraphicsLineItem *pItem = new QGraphicsLineItem();
            pItem->setFlag(QGraphicsItem::ItemIsMovable);
            QPen pen = pItem->pen();
            pen.setColor(QColor(0, 160, 230));
            pen.setWidth(5);
            pItem->setPen(pen);
            // 设置直线位于 (x1, y1) 和 (x2, y2)之间
            pItem->setLine(QLineF(0, 0, 0, 100));

            qDebug()<<"222";
        }else if(selectedAction == deleteAction){

        }

    }

}

QGraphicsLineItem* IconItemGroup::getItem(qreal x1, qreal y1, qreal x2, qreal y2){

    QGraphicsLineItem *pItem = new QGraphicsLineItem();

    //pItem->setFlag(QGraphicsItem::ItemIsMovable);
    QPen pen = pItem->pen();
    pen.setColor(QColor(0, 160, 230));
    pen.setWidth(5);
    pItem->setPen(pen);
    // 设置直线位于 (x1, y1) 和 (x2, y2)之间
    pItem->setLine(x1, y1, x2, y2);

    return pItem;
}
