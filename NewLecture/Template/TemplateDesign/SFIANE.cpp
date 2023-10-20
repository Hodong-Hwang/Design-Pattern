#include <iostream>


//함수 찾는 순서
// 1. exactly mathcing
// 2. template 
// 3. variable argument.

// using namespace std;

// template <typename T>
// void foo (T t) {std:: cout << "T" << std:: endl;}

// void foo (int t) {std::cout << "int" << std::endl;}

// void foo( ...) {std::cout <<"..."<<std::endl;}


template <typename T>
typename T::type foo(T t)
{
    std::cout << "T "<< std::endl;
}
void foo( ...) {std::cout <<"..."<<std::endl;}
int main()
{
    foo(3);
}