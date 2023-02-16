#include <iostream>
#include <type_tratis>
char foo(int a ) {return 0;}

short foo(double a ) {return 0;}

template <typename T> void foo(T a){}
template <typename T> void goo(T::value_type a){}

int main()
{
    int n = 10;
    std::cout <<sizeof(n) <<std::endl;
    std::cout <<sizeof(foo(3)) <<std::endl;
    std::cout <<sizeof(foo(3.14)) <<std::endl;
    std::vector v(10,3);
}