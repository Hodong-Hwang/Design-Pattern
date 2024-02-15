#include <iostream>
class Point
{
    int x,y;
    public :
    Point(int a, int b) : x{a}, y{b} {std::cout <<"Pointer" <<std::endl; }
};

int main()
{
    void* p = operator new (sizeof(Point));

    std::cout << p <<std::endl;
    operator delete(p);
}
// new -> memeory 할당 ->생성장 할당.

// void * p = operator new(sizeof(Point)) // 메모리만 할당.
// Point* p1 = new(p)Point(1,2); "placement new"

// delete 
// p1->~Point();
// operator delete(p1);