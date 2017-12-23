#include "TopologyPainter.h"

TopologyPainter::TopologyPainter()
{
    this->W = 0;
    this->H = 0;
    this->idIcon = 0;
    this->idLine = 0;//
}

TopologyPainter::~TopologyPainter(){
   //std::cout<<"~TopologyPainter executed ...."<<std::endl;
}

/*
 * 功能：设置绘制区域尺寸
 * 输入：width - 宽度
 *      height - 高度
 * 输出：无
 */
 void TopologyPainter::setCanvasSize(unsigned int width, unsigned int height){
    this->W = width;
    this->H = height;
    std::cout<<"mainLayout[width, height]: "<<W<<" "<<H<<std::endl;
 }

/*
 * 功能：设置各类图标的长宽属性，未调用过此函数进行设置的类型值无效
 * 输入：type - 图标类型
 *      width - 宽度
 *      height - 高度
 * 输出：无
 */
void TopologyPainter::setIconType(unsigned int type, unsigned int width, unsigned int height){
    //判断该类型的图标是否存在?

    list<unsigned int>::iterator it = find(this->commonIconTypes.begin(), this->commonIconTypes.end(), type); // 查找list中是否有元素type
    if (it != this->commonIconTypes.end()){//存在该类型图标
        list<TopologyIcon *>::iterator testiterator;
        for (testiterator = this->commonIcons.begin(); testiterator != this->commonIcons.end(); ++testiterator)
        {
            TopologyIcon *kk = *testiterator;
            if(kk->type()==type){//根据图标type值设置数据库中该类型图标的长、宽属性
                kk->setW(width);
                kk->setH(height);
                cout<<"setIconType sucess,iconType:"<<type<<" w:"<<width<<" h:"<<height<<endl;
                break ;
            }
        }
    }else{
        cout<<"setIconType failure,doesn't exist iconType:"<<type<<endl;
    }

}

/*
 * 功能：添加图标
 * 输入：type - 图标类型
 * 输出：大于0代表图标标识，由程序自动分配；小于等于0代表添加失败
 */
int TopologyPainter::addIcon(unsigned int type){
    this->fullIconName="";
    int temp = -1; //默认添加失败
    //判断该类型的图标是否存在?
    list<unsigned int>::iterator it = find(this->commonIconTypes.begin(), this->commonIconTypes.end(), type); // 查找list中是否有元素type

    if (it != this->commonIconTypes.end()){ //数据库中存在该类型图标
        list<TopologyIcon *>::iterator testiterator;
        for (testiterator = this->commonIcons.begin(); testiterator != this->commonIcons.end(); ++testiterator)
        {
            TopologyIcon *kk = *testiterator;
            if(kk->type()==type){
                this->idIcon+=1; //输出标识自动累加，后期可以使用UUID
                temp = this->idIcon;

                TopologyIcon* icon = new TopologyIcon();
                icon->setType(type);
                icon->setId(this->idIcon);//设置图标标识符

                icon->setW(kk->w());//......
                icon->setH(kk->h());

                //根据type获取fullname
                this->fullIconName= kk->getIconPath();

                this->allContainIcons.push_back(icon); //画布中现有图标添加更新
                this->allContainIconIds.push_back(this->idIcon); //画布中现有图标标识更新
                cout<<"+++++++++++++++++++++addIcon success,iconType: "<<type<<", iconId:" <<temp<<" w:"<<icon->w()<<" h:"<<icon->h()<<endl;

                break ;
            }
        }

    }else { //数据库中不存在该类型图标
        cout<<"addIcon failure,doesn't exist iconType:"<<type<<" return iconId:"<<temp<<endl;
    }

    return temp;
}

string TopologyPainter::getFullIconName(){
    return this->fullIconName;
}

/*
 * 功能：删除图标
 * 输入：id - 图标标识
 * 输出：true代表成功，false代表失败
 */
bool TopologyPainter::deleteIcon(unsigned int id){
    bool flagdeleteIcon = false;//删除图标默认值
    //判断图标id是否存在?
    list<unsigned int>::iterator it = find(this->allContainIconIds.begin(), this->allContainIconIds.end(), id); // 查找list中是否有元素type
    if (it != this->allContainIconIds.end()){ //如果存在该图标

        //从现有画布中删除存在的图标
        list<TopologyIcon *>::iterator testiterator;
        for (testiterator = this->allContainIcons.begin(); testiterator != this->allContainIcons.end(); ++testiterator)
        {
            TopologyIcon *kk = *testiterator;
            if(kk->id()==id){
                this->allContainIcons.erase(testiterator);//删除图标
                break ;
            }
        }

        //从现有画布中删除存在的图标id
        this->allContainIconIds.erase(it);
        flagdeleteIcon = true;//更改输出值

        cout<<"deleteIcon success, iconid:"<<id<<"  flagdeleteIcon:"<<flagdeleteIcon <<endl;
    }else {
        cout<<"deleteIcon failure,doesn't exist iconId:"<<id<<"  flagdeleteIcon:"<<flagdeleteIcon<<endl;
    }

    //this->printIconIds();
    return flagdeleteIcon;
}

/*
 * 功能：添加连线
 * 输入：type - 连线类型，枚举型
 *      start - 起点所连图标的标识
 *      end - 终点所连图标的标识
 * 输出：大于0代表连线标识，由程序自动分配；小于等于0代表添加失败
 */
int TopologyPainter::addLine(LineType type, unsigned int start, unsigned int end){
    int temp = -1; // 默认连线添加失败

    //判断是否为连线
    if(type==Line|type==Polyline){
        //判断连线起点、终点所连图标标识是否存在？
        list<unsigned int>::iterator itS = find(this->allContainIconIds.begin(), this->allContainIconIds.end(), start); // 查找画布中现有图标标识id
        list<unsigned int>::iterator itE = find(this->allContainIconIds.begin(), this->allContainIconIds.end(), end);
        if ( (itS != this->allContainIconIds.end()) &&  (itE != this->allContainIconIds.end()) ){ //起点、终点图标id均存在
            //
            this->idLine+=1;//连线id累加分配
            temp = this->idLine;
            this->allContainLineIds.push_back(temp);//画布中现有连线ids更新

            TopologyLine * tpLine = new TopologyLine();
            tpLine->setStart(start);
            tpLine->setEnd(end);
            tpLine->setId(temp);
            if(type==Line){
                tpLine->setType(1);//直线为1
            }else{
                tpLine->setType(2);//折线为2
            }
            this->allContainLines.push_back(tpLine);//画布中现有连线更新

            cout<<" add Line success..... lineId:"<<temp<< "  s:" <<start<<" e:"<<end<<endl;
        }else{
            cout<<" add Line failure, start or end not exist..... lineId:"<<temp<<endl;
        }
    }else{
        cout<<" add Line failure, LineType not exist..... lineId:"<<temp<<endl;
    }

    return temp;
}

/*
 * 功能：删除连线
 * 输入：id - 连线标识
 * 输出：true代表成功，false代表失败
 */
bool TopologyPainter::deleteLine(unsigned int id){
    bool flagdeleteLine = false; //删除连线默认值

    //判断连线id是否存在?
    list<unsigned int>::iterator it = find(this->allContainLineIds.begin(), this->allContainLineIds.end(), id); // 查找list中是否有元素type
    if (it != this->allContainLineIds.end()){ //如果存在该连线

        //从现有画布中删除存在的连线
        list<TopologyLine *>::iterator testiterator;
        for (testiterator = this->allContainLines.begin(); testiterator != this->allContainLines.end(); ++testiterator)
        {
            TopologyLine *line = *testiterator;
            if(line->id()==id){
                this->allContainLines.erase(testiterator);//删除连线
                break ;
            }
        }
        this->allContainLineIds.erase(it);//删除连线id
        flagdeleteLine = true;//更改输出值
        cout<<"deleteLine success, lineid:"<<id<<"  flagdeleteLine:"<<flagdeleteLine <<endl;
    }else {
        cout<<"deleteLine failure,doesn't exist lineId:"<<id<<"  flagdeleteLine:"<<flagdeleteLine<<endl;
    }

    return  flagdeleteLine;
}

/*
 * 功能：重新进行布局计算
 * 输入：无
 * 输出：无
 */
void TopologyPainter::updateLayout(){
    //首先打印画布基本信息
    cout<<"icon numb:"<<this->getIcons().size()<<" line numb:"<<this->getLines().size()<<endl;
    this->printIcons();
    this->printLines();



}

/*
 * 功能：获取所有图标信息，且通过指针可以直接修改其属性
 * 输入：无
 * 输出：图标列表
 */
list<TopologyIcon *> TopologyPainter::getIcons(){
     return this->allContainIcons;
}

/*
 * 功能：获取所有连线信息，且通过指针可以直接修改其属性
 * 输入：无
 * 输出：连线列表
 */
list<TopologyLine *> TopologyPainter::getLines(){
     return this->allContainLines;
}


//---------------------------------------------------------------------------
/**
 * @brief TopologyPainter::setInitParameters
 */
void TopologyPainter::setInitParameters(list<TopologyIcon *> elementIcons){

    //设置库图标  list方法
    this->commonIcons = elementIcons;

    cout<<endl;
    cout<<"********************* iconLibs in database: ************************* "<<endl;
    cout<<" commeElments types: ";
    //list遍历
    list<TopologyIcon *>::iterator testiterator;
    for (testiterator = this->commonIcons.begin(); testiterator != this->commonIcons.end(); ++testiterator)
    {
        TopologyIcon *kk = *testiterator;
        this->commonIconTypes.push_back(kk->type());//图标类型存储变量
        cout << kk->type() << " ";
    }

    cout<<endl;
    cout<<" the iconType size: " <<this->commonIconTypes.size() <<endl;
    cout<<"******************************************************************* "<<endl;
    cout<<endl;
}

/**
 * 功能：打印画布中现有图标基本信息
 * @brief TopologyPainter::printIcons
 */
void TopologyPainter::printIcons(){
    cout <<endl;
    cout <<"========================================"<<endl;
    cout <<"all exist Icons size:"<<this->allContainIcons.size()<<endl;
    list<TopologyIcon *>::iterator testiterator;
    for (testiterator = allContainIcons.begin(); testiterator != allContainIcons.end(); ++testiterator)
    {
        TopologyIcon *kk = *testiterator;
        cout <<"type:"<<kk->type() << " id:"<<kk->id()<<" w:"<<kk->w()<<" h:"<<kk->h()<<endl;
    }
    cout <<"========================================"<<endl;
}

void TopologyPainter::printIconIds(){
    //cout <<endl;
    cout <<"========================================"<<endl;
    cout <<"all exist IconIds size:"<<this->allContainIconIds.size()<<endl;
    cout <<"all iconIds: ";
    list<unsigned int>::iterator testiterator;
    for (testiterator = allContainIconIds.begin(); testiterator != allContainIconIds.end(); ++testiterator)
    {
        cout<<*testiterator <<" ";
    }
    cout <<endl;
    cout <<"========================================"<<endl;
    cout <<endl;
}


void TopologyPainter::printLines(){
    //cout <<endl;
    cout <<"========================================"<<endl;
    cout <<"all exist lines size:"<<this->allContainLines.size()<<endl;
    list<TopologyLine *>::iterator testiterator;
    for (testiterator = allContainLines.begin(); testiterator != allContainLines.end(); ++testiterator)
    {
        TopologyLine *line = *testiterator;
        if(line->type()==1){
            cout <<"type:line, "<<"lineid:"<<line->id()<<" s:"<<line->start()<<" e:"<<line->end()<<endl;
        }
        if(line->type()==2){
            cout <<"type:polyline, "<<"lineid:"<<line->id()<<" s:"<<line->start()<<" e:"<<line->end()<<endl;
        }
    }
    cout <<endl;
    cout <<"========================================"<<endl;
    cout <<endl;

}
void TopologyPainter::printLineIds(){
    //cout <<endl;
    cout <<"========================================"<<endl;
    cout <<"all exist lineIds size:"<<this->allContainLineIds.size()<<endl;
    cout <<"all lineIds: ";
    list<unsigned int>::iterator testiterator;
    for (testiterator = allContainLineIds.begin(); testiterator != allContainLineIds.end(); ++testiterator)
    {
        cout<<*testiterator <<" ";
    }
    cout <<endl;
    cout <<"========================================"<<endl;
    cout <<endl;
}

list<unsigned int> TopologyPainter::getAllContainIconIds(){
    return this->allContainIconIds;
}
