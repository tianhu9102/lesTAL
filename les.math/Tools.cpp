#include "Tools.h"

/**
 * function: store the base icons and lines
 * @brief Tools::Tools
 */
Tools::Tools()
{
    //初始化时即加载部分预设的图标元素
    TopologyIcon *icon1 = new TopologyIcon();
    icon1->setType(677834);
    TopologyIcon *icon2 = new TopologyIcon();
    icon2->setType(53);
    TopologyIcon *icon3 = new TopologyIcon();
    icon3->setType(25);
    TopologyIcon *icon4 = new TopologyIcon();
    icon4->setType(653);

    this->commonIcons.push_back(icon1);
    this->commonIcons.push_back(icon2);
    this->commonIcons.push_back(icon3);
    this->commonIcons.push_back(icon4);
}

list<TopologyIcon *> Tools::getDatabaseIcons(){
    return this->commonIcons;
}

list<TopologyLine *> Tools::getDatabaseLines(){
    return this->commonLines;
}


void Tools::setDatabaseIcons(TopologyIcon *icon){
    this->commonIcons.push_back(icon);
}

void Tools::setDatabaseLines(){

}
