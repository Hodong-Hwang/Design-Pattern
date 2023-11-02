
//temporary is rvalue;
#include <iostream>
class Point
{
    public:
    int x,y;

Point (int x, int y) :x(x),y(y) {std::cout << "Point"<<std::endl;}
~Point()  {std::cout << "~Point"<<std::endl;}
    void set(int x, int y) {x=x;y=y;}
};

int main()
{
    Point pt(1,2); //named object
    Point (1,2); // uname object

    //temoporary 특징.
    // 1. ravlue
    //Point (1,2).x=0;// error
    //Point (1,2).set(1,2) // ok
    // Point* ptr=&pt // ok
    // Point& r2=Point(1,2)// error
    // Point&& r2=Point(1,2)// ok
    // const Point& r3=Point(1,2) // ok

    std::cout << "---------------" << std::endl;
}