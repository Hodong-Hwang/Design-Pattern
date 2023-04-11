#include <iostream>
#include <vector>

class Point
{
    int x,y;
    public:
    Point(int a,int b):x(a),y(b){}
};


int main ()
{
    std::vector<Point> v1;
    std::vector<Point> v2(10,Point(0,0));
    v2.resize(20,Point(0,0));

}