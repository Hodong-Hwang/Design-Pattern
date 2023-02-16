
// 함수 찾는 순서
// 1. exactly matching
// 2. template
// 3. variable Argument.
#include <iostream>
using namespace std;

// template <typename T>
// void foo(T t){cout << "T" <<endl;}

// template <typename T>
// int foo(T t){cout << "T" <<endl;}

template <typename T>
typename T::type foo(T t){cout << "T" <<endl;}

// SIFANE (substititution Failure is Not An Error)
// 치환 실패는 에러는 아니다.
// 

void foo(...){cout << "..." <<endl;}; 
int main()
{
    foo(3);
    return 0;
}