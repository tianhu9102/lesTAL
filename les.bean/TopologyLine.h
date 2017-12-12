#ifndef TOPOLOGYLINE_H
#define TOPOLOGYLINE_H

#include "TopologyPoint.h"
#include <list>

class TopologyLine
{
private:
    unsigned int _id;
    unsigned int _type;
    unsigned int _iconIdS;
    unsigned int _iconIdE;

public:
    TopologyLine();
    ~TopologyLine();

    unsigned int id();	//获取连线标识
    void setId(unsigned int id);	//设置连线标识

    unsigned int type();	//获取连线类型
    void setType(unsigned int type);	//设置连线类型

    unsigned int start();	//获取起点所连图标的标识
    void setStart(unsigned int iconId);	//设置起点所连图标的标识

    unsigned int end();	//获取终点所连图标的标识
    void setEnd(unsigned int iconId);	//设置终点所连图标的标识

    //注意：对于折线来说，除了端点，还有顶点，顶点以列表形式输入输出，顶点列表按起点至终点的顺序排列
    list<TopologyPoint *> points();	//获取顶点列表，如果是直线，该函数返回空列表
    void setPoints(const list<TopologyPoint> &points);	//设置顶点列表，如果是直线，该函数无效
};

#endif // TOPOLOGYLINE_H
