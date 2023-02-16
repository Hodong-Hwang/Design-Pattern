#include <iostream>
#include <functional>
#include <thread>
#include "StopWatch.h"
struct Functor
{
    void operator () (int n ) &
    {
        std::cout <<" operator (" << n << ") &"<< std::endl;
    }
        void operator () (int n ) &&
    {
        std::cout <<" operator (" << n << ") &&"<< std::endl;
    }
};


template <typename F, typename ... T>
decltype(auto) chronometry(F&& f, T&& ... arg)
{
    // 현재의 시간 보관
    StopWatch sw;
    return std::invoke(std::forward<F>(f),std::forward<T>(arg)...);
}

void foo(int n ){
    std::this_thread::sleep_for(std::chrono::seconds(n));
}

int main()
{
    Functor f;
    f(10); // f.operator();
    chronometry(f,10);
    chronometry(Functor(),10);
    chronometry(foo,2);

}