#ifndef TOPOLOGYPAINTER_H
#define TOPOLOGYPAINTER_H

#include <list>
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>

#include "TopologyLine.h"
#include "TopologyIcon.h"

class TopologyPainter
{
public:
    enum LineType	//连线类型
    {
        Line,	//直线
        Polyline//折线
    };

private:
    //页面布局大小
    unsigned int W;
    unsigned int H;

    //存储库图标
    list<TopologyIcon *> commonIcons;//数据库中图标元素
    list<unsigned int> commonIconTypes;//数据库中图标类型

    list<TopologyIcon *> allContainIcons;//画布中现有图标
    list<unsigned int> allContainIconIds;//画布中现有图标ids

    list<TopologyLine *> allContainLines;//画布中现有连线
    list<unsigned int> allContainLineIds;//画布中现有连线ids

    //自动分派的画布中图标标识
    int idIcon;

    //自动分派的画布中连线标识
    int idLine;

    //
    string fullIconName;

public:
    TopologyPainter();
    ~TopologyPainter();

    void setCanvasSize(unsigned int width, unsigned int height);
    void setIconType(unsigned int type, unsigned int width, unsigned int height);
    int addIcon(unsigned int type);
    bool deleteIcon(unsigned int id);
    int addLine(LineType type, unsigned int start, unsigned int end);
    bool deleteLine(unsigned int id);
    void updateLayout();
    list<TopologyIcon *> getIcons();
    list<TopologyLine *> getLines();

    //自定义函数
    void setInitParameters(list<TopologyIcon *> elementIcons);
    void printIcons();
    void printIconIds();
    void printLines();
    void printLineIds();

    list<unsigned int> getAllContainIconIds();

    string getFullIconName();

};

#endif // TOPOLOGYPAINTER_H
