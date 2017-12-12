#include "TopologyPoint.h"

TopologyPoint::TopologyPoint()
{
    this->_x = 0;
    this->_y = 0;

}

TopologyPoint::~TopologyPoint(){

}

unsigned int TopologyPoint::x(){
    return this->_x;
}

void TopologyPoint::setX(unsigned int x){
    this->_x = x;
}

unsigned int TopologyPoint::y(){
    return this->_y;
}

void TopologyPoint::setY(unsigned int y){
    this->_y = y;
}
