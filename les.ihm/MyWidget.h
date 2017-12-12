#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QDrag>
#include <QEvent>
#include <QMouseEvent>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDir>
#include <qdebug.h>

class MyWidget : public QListWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = 0);

    void setConstruct(QString iconpath);
    QPoint endPos;

protected:
    void dropEvent(QDropEvent *event);

};
#endif // MYWIDGET_H
