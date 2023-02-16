#include <iostream>
#include <functional>
// template <typename F, typename T>
// void chronometry3(F f, T&& arg)
// {
//     // 현재의 시간 보관
//     f(std::forward<T>(arg));
// }


template <typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
    // 현재의 시간 보관
    return f(std::forward<T>(arg)...);
}


// 멤버 함수에 대해서도 적용하기 위함.
template <typename F, typename ... T>
decltype(auto) chronometry2(F f, T&& ... arg)
{
    // 현재의 시간 보관
    return std::invoke(f,(std::forward<T>(arg)...));
}

void foo(int n) {}
int& goo(int a, int& b,int && c) {b=20; return b;}
void  hoo(){};


int main ()
{
    int n = 10 ;
    int& ret = chronometry(goo,10,n,10);
    chronometry(hoo);

    std::cout << n << std::endl;
    return 0;
}
