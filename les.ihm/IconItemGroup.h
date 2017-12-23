#ifndef IconItemGroup_H
#define IconItemGroup_H

#include <QObject>
#include <QGraphicsItemGroup>
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include <QGraphicsLineItem>
#include <QPen>
#include <QMenu>
#include <qdebug.h>
#include <QGVScene.h>
#include <QGraphicsViewEc.h>

class IconItemGroup :public QObject, public QGraphicsItemGroup
{
    Q_OBJECT

public:
    IconItemGroup(QGraphicsItemGroup *parent=0);

    IconItemGroup *getIconTextItems(QGVScene *_scene, QString picName, int tmp);

    QGraphicsLineItem* getItem(qreal x1, qreal y1, qreal x2, qreal y2);

private:
    QGVScene *scene;


protected:
   void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);

};

#endif // IconItemGroup_H
