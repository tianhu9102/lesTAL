#include "IconWidget.h"

IconWidget::IconWidget(QWidget *parent):QListWidget(parent)
{
    setCurrentRow(10);
    setDragEnabled(true);
    setViewMode(QListView::IconMode);
    setResizeMode(QListView::Adjust);
    setDragDropMode(QAbstractItemView::DragDrop);
    //setAcceptDrops(true);//设置QListWidget的Item项可以被拖拽
    //setSelectionMode(QAbstractItemView::ContiguousSelection );
}

void IconWidget::setConstruct(){

    QListWidgetItem * listItem;
   // QDir dir(iconpath);//如果不加地址，则就在当前目录下遍历
    QDir dir(":topoIcons");
    QStringList filters;
    //filters << "*.jpg"<<"*.png";//设置过滤类型
    filters << "*.jpg";//
    dir.setNameFilters(filters);//设置文件名的过滤
    QFileInfoList list = dir.entryInfoList();

    if(list.length()!=0)
        for (int i = 0; i < list.size(); ++i){
            //QListWidgetItem* lst = new QListWidgetItem(QIcon(":/topoIcons/"+list.at(i).fileName()), list.at(i).fileName().split(".")[0], listWidget);
            //QListWidgetItem* lst = new QListWidgetItem(QIcon(":/topoIcons/"+list.at(i).fileName()), QString::number(i, 10), listWidget);

            //listItem = new QListWidgetItem(NoStr,this);
            listItem = new QListWidgetItem(QIcon(":/topoIcons/"+list.at(i).fileName()), list.at(i).fileName().split(".")[0], this);

            listItem->setSizeHint(QSize(80,80));
            listItem->setIcon(QIcon(":topoIcons/"+list.at(i).fileName()));
            addItem(listItem);
        }
    else {
        qDebug()<<"no file";
    }
}

void IconWidget::setTmp(int tp){
    this->tmp = tp;
}

int IconWidget::setView(QGraphicsViewEc *view,QGVScene *scene){
    this->_view = view;
    this->_scene = scene;

    //this->_view->setScene(this->_scene);
    return 1;
}

// http://blog.csdn.net/xuguangsoft/article/details/8522184
void IconWidget::dropEvent( QDropEvent *event )
{
    this->itemStr = "";
    QListWidgetItem* item;
    IconWidget *source = qobject_cast<IconWidget *>(event->source());
    if (source && source == this)
    {
        //得到鼠标移动到的坐标
        endPos = event->pos();
        //通过endPos获取鼠标位置所在的行
        QListWidgetItem *Enditem = itemAt(endPos);
        //判断该位置是否在Item上
        int rowCount = row(Enditem);

        if(rowCount >= 0)
        {
            QList<QListWidgetItem*> pListItem;
            pListItem =  source->selectedItems();
            int count = pListItem.count();
            if(count)
            {
                for(int i= 0;i<count;i++)
                {
                    this->tmp +=120;
                    item = pListItem.at(i);
                    this->itemStr = item->text();

                    //选中的图标icon
                    QString picName= ":topoIcons/"+this->itemStr+".jpg";

                    //组合方式显示图标+文字
                    IconItemGroup* iig = new IconItemGroup();
                    QGraphicsItemGroup* pGroup = iig->getIconTextItems(this->_scene,picName,tmp);

                    this->_scene->addItem(pGroup);
                    qDebug()<<"xxx:"<<this->itemStr<<" ++ "<<pGroup->pos();

                }
            }
        }
    }
}

QString IconWidget::getChoosedItem(){
    return this->itemStr;
}
