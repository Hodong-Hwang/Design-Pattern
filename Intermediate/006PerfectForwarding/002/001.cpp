#include <iostream>
template <typename F>
void chronometry(F f, int& arg)
{
    f(arg);
}

template <typename F>
void chronometry(F f, int&& arg)
{
    // 현재의 시간 보관
    f(static_cast<int&&>(arg));
    // 함수 소요시간 출력
}

// Forwarding Reference!! 
// template <typename F, typename T>
// void chronometry2(F f, int& arg)
// {
//     f(arg);
// }

template <typename F, typename T>
void chronometry2(F f, T&& arg)
{
    // 현재의 시간 보관
    f(static_cast<T&&>(arg));
}

// it is smae as 2 version
template <typename F, typename T>
void chronometry3(F f, T&& arg)
{
    // 현재의 시간 보관
    f(std::forward<T>(arg));
}
void foo(int n) {}
void goo(int&r) {r=20;}
void hoo(int&& r){}

int main ()
{
    int n =0 ;
    chronometry2 (goo, n);
    chronometry2 (hoo,10);
    std::cout << n <<std::endl;
}