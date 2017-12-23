#ifndef QTABLEWIDGETTP_H
#define QTABLEWIDGETTP_H

#include <QWidget>
#include <QTableWidget>
#include <qdebug.h>
#include "Tools.h"
#include "TopologyPainter.h"
#include "QGVScene.h"
#include "QGraphicsViewEc.h"
#include "QGVNode.h"
#include "QGVEdge.h"
#include "QGVSubGraph.h"
#include <QHBoxLayout>

namespace Ui {
class QTableWidgetTp;
}

class QTableWidgetTp : public QWidget
{
    Q_OBJECT

public:
    explicit QTableWidgetTp(QWidget *parent = 0);
    ~QTableWidgetTp();

    void setInitParameters();

private:
    Ui::QTableWidgetTp *ui;

    list<TopologyIcon *> listTIcons;

    Tools tools;
    TopologyPainter tPainter;

    QGVScene *scene;
    QGraphicsViewEc* view;


public slots:
    void addIconF();
    void addLineF();
    void autoLayout();
};

#endif // QTABLEWIDGETTP_H
