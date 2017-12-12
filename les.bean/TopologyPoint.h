#ifndef TOPOLOGYPOINT_H
#define TOPOLOGYPOINT_H



using namespace std;
class TopologyPoint
{
    private:
        unsigned int _x;
        unsigned int _y;

    public:
        TopologyPoint();
        ~TopologyPoint();

        unsigned int x();	//获取点的x值
        void setX(unsigned int x);	//设置点的x值

        unsigned int y();	//获取点的y值
        void setY(unsigned int y);	//设置点的y值
};
#endif // TOPOLOGYPOINT_H
