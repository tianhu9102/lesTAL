#ifndef IconWidget_H
#define IconWidget_H

#include <QDrag>
#include <QEvent>
#include <QMouseEvent>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDir>
#include <qdebug.h>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QTextDocument>

#include "QGraphicsViewEc.h"
#include "QGVScene.h"
#include "QGVNode.h"

#include "IconItemGroup.h"


class IconWidget : public QListWidget
{
    Q_OBJECT
public:
    IconWidget(QWidget *parent = 0);

    void setConstruct();
    QPoint endPos;

    QGraphicsViewEc* _view;
    QGVScene *_scene;
    //QGraphicsView *_view;
    //QGraphicsScene *_scene;
    //int setView(QGraphicsView *view,QGraphicsScene *scene);
    int setView(QGraphicsViewEc *view,QGVScene *scene);

    QString itemStr;
    QString getChoosedItem();

    void setTmp(int tp);

private:
     int tmp=0;

protected:
    void dropEvent(QDropEvent *event);

};
#endif // IconWidget_H
