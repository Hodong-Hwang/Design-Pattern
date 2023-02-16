#include <iostream>
#include <functional>
#include "StopWatch.h"
template <typename F, typename ... T>
decltype(auto) chronometry(F&& f, T&& ... arg)
{
    // 현재의 시간 보관
    StopWatch sw;
    return std::invoke(std::forward<F>(f),std::forward<T>(arg)...);
}

void foo(int* p){}
void hoo(std::pair<int ,int> p){}
void goo(int a){};
void goo(int a, int b) {} ;
int main ()
{
    foo(0); //okay
    int arg = 0 ;
   // foo(arg); //error

   // chronometry(foo,0); //error
    chronometry(foo,nullptr); // nullppt_rt
    //chronometry(hoo,{1,2}); //errojr
    chronometry(hoo,std::pair{1,2}); //errojr
    //chronometry(goo,1,2); //error
    chronometry(static_cast<void(*)(int,int)>(goo),1,2); //error
    return 0;
}