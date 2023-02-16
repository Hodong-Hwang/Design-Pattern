#include <iostream>

struct Point
{
    int x;
    int y;
    /* data */
};

int main ()
{
    int num = 0;
    int *p1 =&num;
    int Point::*p2 = &Point::y; // pointer 구조체 안에서 offfset이 존재함.
    *p1 = 10 ;
    Point pt ;
    pt.*p2 =10; // error -> *((char*)&pt + p2 )= 10
    printf("%p\n",p2);

}
