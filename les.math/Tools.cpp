#include "Tools.h"

/**
 * function: store the base icons and lines
 * @brief Tools::Tools
 */

Tools::Tools()
{
    //获取图标库
    QDir dir(":topoIcons");
    QStringList filters;
    //filters << "*.jpg"<<"*.png";//设置过滤类型
    filters << "*.jpg";//
    dir.setNameFilters(filters);//设置文件名的过滤
    QFileInfoList list = dir.entryInfoList();

    qDebug()<<"icons::: "<<list.size();
    if(list.length()!=0)
        for (int i = 1; i <= list.size(); ++i){
            TopologyIcon *icon1 = new TopologyIcon();
            icon1->setType(i);
            icon1->setW(40);
            icon1->setH(30);
            icon1->setName(list.at(i-1).fileName().split(".")[0].toStdString());
            icon1->setIconPath( ":/topoIcons/"+list.at(i-1).fileName().toStdString());
            this->commonIcons.push_back(icon1);
        }
    else {
        qDebug()<<"no file";
    }
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
