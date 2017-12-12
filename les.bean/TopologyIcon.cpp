#include "TopologyIcon.h"

TopologyIcon::TopologyIcon()
{
    this->_id = -1;
    this->_type = -1;
    this->_x = 0;
    this->_y = 0;

    this->_w=0;
    this->_h=0;
}

TopologyIcon::~TopologyIcon(){

}

//获取图标标识
unsigned int TopologyIcon::id(){
    return this->_id;
}

//设置图标标识
void TopologyIcon::setId(unsigned int id){
    this->_id = id;
}

//获取图标类型
unsigned int TopologyIcon::type(){
    return this->_type;
}

//设置图标类型
void TopologyIcon::setType(unsigned int type){
    this->_type = type;
}

//注意：图标位置用左上角点的坐标表示
//获取图标位置的x值
unsigned int TopologyIcon::x(){
    return this->_x;
}

//设置图标位置的x值
void TopologyIcon::setX(unsigned int x){
   this->_x = x;
}

//获取图标位置的y值
unsigned int TopologyIcon::y(){
    return this->_y;
}

//设置图标位置的y值
void TopologyIcon::setY(unsigned int y){
    this->_y = y;
}

//获取图标位长
unsigned int TopologyIcon::w(){
    return this->_w;
}

//设置图标长
void TopologyIcon::setW(unsigned int w){
    this->_w = w;
}

//获取图标宽
unsigned int TopologyIcon::h(){
    return this->_h;
}

//设置图标宽
void TopologyIcon::setH(unsigned int h){
    this->_h = h;
}
