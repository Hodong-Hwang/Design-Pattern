#include <iostream>

char foo(int a) {return 0; }
short foo(double d) {return 0;}


// template <typename T> void reset_container (T& c)
// {
//     c.resize(10);
//     // resize 함수가 있는지 조사
//     // 함수 조사가 있는지 확인...
//     bool b = has_resize<T>::value;
// }

int main()
{
    int n = 10 ;
    std::cout <<sizeof(n) <<std::endl; //4;
    // std::cout << sizeof(foo) << error
    // 함수 호출 값만 return함.
    std::cout << sizeof(foo(3)) <<std::endl; //1
    std::cout << sizeof(foo(3.3))<< std::endl; // 2
}