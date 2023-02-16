#include <iostream>
#include <functional>
struct Point
{
    int x;
    int y;
    /* data */
};

int main ()
{

    int Point::*p2 = &Point::y; // pointer 구조체 안에서 offfset이 존재함.
    Point obj;
    obj.*p2 =10;
    (&obj)->*p2 =10;

    std::invoke(p2,obj)= 20 ; //obj.y;
    int n = std::invoke(p2,obj);
    std:: cout << n <<std::endl;
    std:: cout << obj.y <<std::endl;


}
