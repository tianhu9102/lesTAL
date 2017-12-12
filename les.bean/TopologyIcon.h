#ifndef TOPOLOGYICON_H
#define TOPOLOGYICON_H


class TopologyIcon
{

private:
    unsigned int _id;
    unsigned int _type;
    unsigned int _x;
    unsigned int _y;

    //---------------
    unsigned int _w;
    unsigned int _h;

public:
    TopologyIcon();
    ~TopologyIcon();

    unsigned int id();	//获取图标标识
    void setId(unsigned int id);	//设置图标标识

    unsigned int type();	//获取图标类型
    void setType(unsigned int type);	//设置图标类型

    //注意：图标位置用左上角点的坐标表示
    unsigned int x();	//获取图标位置的x值
    void setX(unsigned int x);	//设置图标位置的x值

    unsigned int y();	//获取图标位置的y值
    void setY(unsigned int y);	//设置图标位置的y值


    unsigned int w();	//获取图标位长
    void setW(unsigned int w);	//设置图标长

    unsigned int h();	//获取图标宽
    void setH(unsigned int h);	//设置图标宽

};

#endif // TOPOLOGYICON_H
