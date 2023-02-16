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
    void *p =operator new(sizeof(Point));
    std::cout << p <<std::endl;
    // 생성자 호출 안됨.
    operator delete(p);
}

void ex2()
{
    // 생성자 호출
    void *p =operator new(sizeof(Point));
    std::cout << p <<std::endl;
    Point *p1 = new(p) Point(1,2); // placement new
    // 생성자 호출 안됨.
    p1->~Point();
    operator delete(p1);
}

void ex3()
{
    void *p1 =operator new(sizeof(Point));
    new(p1) Point(1,2); // placement new
    operator delete(p1);

    Point *p2 =static_cast<Point*>(operator new(sizeof(Point)));
    std::construct_at(p2,2,3);

    std::destroy_at(p2);

    operator delete(p2);
}
int main ()
{

    ex3();
    return 0;
}