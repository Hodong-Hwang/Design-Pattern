#include <iostream>

struct Point
{
    /* data */
    int x;
    int y;;
};


int main()
{
    int num = 0;
    int *p1 =&num;
    int Point::*p = &Point::y; // p는 무엇을 담고 있는가?
    // p의경우 반드시 안들어가도되지만, pointer 구조체 안에서 offset(4)를 담고 있다.
    // x에서 4바이트 떨어진곳
    *p1=10;
    //
    Point pt;
    pt.*p=10; // ((char*)&pt+p2)=10; // callable인 경우 모두 사용가능
    
}