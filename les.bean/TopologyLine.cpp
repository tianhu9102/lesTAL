#include "TopologyLine.h"

TopologyLine::TopologyLine()
{
    this->_id = -1;
    this->_type = -1;
    this->_iconIdS = 0;
    this->_iconIdE = 0;
}

TopologyLine::~TopologyLine(){

}

//获取连线标识
unsigned int TopologyLine::id(){
    return this->_id;
}

//设置连线标识
void TopologyLine::setId(unsigned int id){
    this->_id = id;
}

//获取连线类型
unsigned int TopologyLine::type(){
    return this->_type;
}

//设置连线类型（直线和折线）
void TopologyLine::setType(unsigned int type){
    this->_type = type;
}

//获取起点所连图标的标识
unsigned int TopologyLine::start(){
    return this->_iconIdS;
}

//设置起点所连图标的标识
void TopologyLine::setStart(unsigned int iconId){
    this->_iconIdS = iconId;
}

//获取终点所连图标的标识
unsigned int TopologyLine::end(){
    return this->_iconIdE;
}

//设置终点所连图标的标识
void TopologyLine::setEnd(unsigned int iconId){
    this->_iconIdE = iconId;
}

//注意：对于折线来说，除了端点，还有顶点，顶点以列表形式输入输出，顶点列表按起点至终点的顺序排列
//获取顶点列表，如果是直线，该函数返回空列表
list<TopologyPoint *> TopologyLine::points(){
    list<TopologyPoint *> hj;
    return hj;
}

//设置顶点列表，如果是直线，该函数无效
void TopologyLine::setPoints(const list<TopologyPoint> &points){

}
