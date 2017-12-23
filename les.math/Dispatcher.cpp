#include "Dispatcher.h"


Dispatcher::Dispatcher()
{

}

/**
 * 主测试方法
 * @brief TestDemo::autoCompute
 */
void Dispatcher::autoCompute(){

    //---------------------------  初始化数据库中通用元素   ----------------------------------------
    //第一步：设置画布绘制区域大小
    TopologyPainter tPainter;
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&  Begin set mainLayout's size.... &&&&&&&&&&&&&&&&&&&&&&&&& "<<endl;
    tPainter.setCanvasSize(800,600);

    //第二步：获取通用的图标、连接线等元素
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&  Begin load Icons from Tool.... &&&&&&&&&&&&&&&&&&&&&&&&& "<<endl;
    Tools tools;
    //tools.setDatabaseIcons();//可在此拓展元素库
    tPainter.setInitParameters(tools.getDatabaseIcons()); //初始化参数

    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&  Begin set IconType.... &&&&&&&&&&&&&&&&&&&&&&&&& "<<endl;
    tPainter.setIconType(677834,20,15);
    tPainter.setIconType(53,20,12);
    tPainter.setIconType(656,16,8);//测试1：对于不存在的图标类型，则无法设置图标长宽属性
    tPainter.setIconType(25,16,12);
    tPainter.setIconType(653,16,8);

    //---------------------------  画布中图标的添加、删除操作   ----------------------------------------
    //打印初始化时的画布元素
    //初始化时画布无元素
    tPainter.printIcons();
    tPainter.printIconIds();
    cout<<"=== 00 === current icons number in mainLayout: "<<tPainter.getIcons().size()<<endl; //测试2：

    //---------------------------  添加画布元素   ----------------------------------------
    //操作：添加图标、连线
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&  Begin add Icon.... &&&&&&&&&&&&&&&&&&&&&&&&& "<<endl;
    tPainter.addIcon(677834);//测试3：是否成功添加图标到画布
    tPainter.addIcon(3);
    tPainter.addIcon(53);
    tPainter.addIcon(25);
    tPainter.addIcon(677834);
    tPainter.addIcon(653);
    tPainter.addIcon(25);
    tPainter.setIconType(53,30,22); //测试1：可修改该类型图标长宽属性，便于动态维护
    tPainter.addIcon(53);
    tPainter.addIcon(6);//
    tPainter.addIcon(25);

    tPainter.printIcons();
    tPainter.printIconIds();
    cout<<"=== 11 === current icons number in mainLayout: "<<tPainter.getIcons().size()<<endl;//测试2：

    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&  Begin delete Icon.... &&&&&&&&&&&&&&&&&&&&&&&&& "<<endl;
    bool kk = tPainter.deleteIcon(4);
    cout<<kk<<" kkk"<<endl; //测试4：是否成功删除画布中图标

    bool iii = tPainter.deleteIcon(87);
    cout<<iii<<" iii"<<endl;

    bool mm = tPainter.deleteIcon(4);
    cout<<mm<<" mmm"<<endl;

    bool ppp = tPainter.deleteIcon(7);
    cout<<ppp<<" ppp"<<endl;

    tPainter.printIcons();
    tPainter.printIconIds();
    cout<<"=== 22 === current icons number in mainLayout: "<<tPainter.getIcons().size()<<endl;//测试2：todo:修改属性


    //测试5：
    //添加连线
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&  Begin add Line.... &&&&&&&&&&&&&&&&&&&&&&&&& "<<endl;
    tPainter.printLines();
    tPainter.printLineIds();
    tPainter.addLine(TopologyPainter::Line,5,6);
    tPainter.addLine(TopologyPainter::Polyline,9,5);//测试：添加不成功
    tPainter.addLine(TopologyPainter::Line,1,6);
    tPainter.addLine(TopologyPainter::Line,5,8);
    tPainter.addLine(TopologyPainter::Polyline,3,8);
    tPainter.addLine(TopologyPainter::Line,7,9); //测试：添加不成功
    tPainter.addLine(TopologyPainter::Line,3,6);
    tPainter.addLine(TopologyPainter::Polyline,5,6);
    tPainter.addLine(TopologyPainter::Line,3,2);
    tPainter.printLines();
    tPainter.printLineIds();

    //删除连线
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&  Begin delete Line.... &&&&&&&&&&&&&&&&&&&&&&&&& "<<endl;
    cout<<"ccc: "<<tPainter.getLines().size()<<endl;
    tPainter.deleteLine(77);
    tPainter.printLines();
    tPainter.printLineIds();

    tPainter.deleteLine(4);
    tPainter.printLines();
    tPainter.printLineIds();

    cout<<"ccc: "<<tPainter.getLines().size()<<endl;
    tPainter.deleteLine(2);
    tPainter.printLines();
    tPainter.printLineIds();

    tPainter.deleteLine(4);
    tPainter.printLines();
    tPainter.printLineIds();
    cout<<"ccc: "<<tPainter.getLines().size()<<endl;

    tPainter.updateLayout();
}

// 1.指针和引用的区别  https://www.cnblogs.com/dolphin0520/archive/2011/04/03/2004869.html




