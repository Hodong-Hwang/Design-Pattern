#include <iostream>
#include <new>
#include <memory>
class Point 
{
    int x,y;
    public:
    Point (int a, int b) : x{a}, y{b} { std::cout << "Point Constructor" <<std::endl;}
    ~Point () { std::cout << "~Point" <<std::endl;}
};

void ex1()
{
    Point* p1 =new Point(0,0);
    //Point* p2 =new Point[3]; //error -> it has no default construct
    Point* p3 =new Point[3]{{0,0},{0,0},{0,0}}; 

    Point* p4 = static_cast<Point*> (operator new(sizeof(Point)*3));

    for (int i =0 ; i<3; i++)
    {
        new(&p4[i]) Point(0,0);
        //p4[i].~Point();
        std::destroy_at(&p4[i]);
    }
    delete p1; 
    delete [] p3;

}
int main()
{
    ex1();
}