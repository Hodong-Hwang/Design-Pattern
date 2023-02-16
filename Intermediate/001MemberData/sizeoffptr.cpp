#include<iostream>
struct A
{
    int x;
};
struct B
{
    int y;
};
struct C :public A, public B
{
    int z;
};

int main ()
{
    C cc;
    std::cout <<& cc <<std::endl;
    A* pA =&cc;
    B* pB =&cc; 
    // B의 위치 때문에 다름. 기반 클래스-> 다중 클래스를 찾는 위치. (다중 클래스의 경우)
    std::cout << pA<< std::endl;
    std::cout << pB<< std::endl;
    B* pB1 =static_cast<B*>(&cc); 
    B* pB2 =reinterpret_cast<B*>(&cc); 
    std::cout << pB1<< std::endl;
    std::cout << pB2<< std::endl;
    pB2->y = 10; // cc.x 에 대입
    std::cout << cc.x<< std::endl;


    return 0;

}