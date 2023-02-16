#include <iostream>

void foo(int n) {}
void goo(int&r) {r=20;}
void hoo(int&& r){}
template <class F, class T >
void chronometry(F f, T arg)
{
    // 현재의 시간 보관
    f(arg);
    // 함수 소요시간 출력
}
// 전달 받은 인자들이  값 ,csv 속성 ,value category 없이 잘 보내주어야하는 것.
// T -> T로 변환됨..
// T& ->rvalue 문제 const T& -> const로 변홚맘.

template <typename F>
void chronometry2(F f, int& arg)
{
    // 현재의 시간 보관
    f(arg);
    // 함수 소요시간 출력
}

template <typename F>
void chronometry2(F f, int&& arg)
{
    // 현재의 시간 보관
    f(arg);
    // 함수 소요시간 출력
}

template <typename F>
void chronometry3(F f, int& arg)
{
    // 현재의 시간 보관
    f(arg);
    // 함수 소요시간 출력
}

template <typename F>
void chronometry3(F f, int&& arg)
{
    // 현재의 시간 보관
    f(static_cast<int&&>(arg));
    // 함수 소요시간 출력
}





int main ()
{
    int n= 10 ;
    chronometry2(foo,10);
    chronometry2(goo,n); //

    chronometry3(hoo,10); // rvalue에서 arg가 lvalue의 속성의 변화가 발생함.

    std::cout << n  <<std::endl;
}