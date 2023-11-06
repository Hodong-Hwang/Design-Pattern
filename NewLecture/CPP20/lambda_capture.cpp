#include <iostream>

//Capture parameter pack by value // parameter pack이 캡처가됨.
template <typename ...Args> auto f1(Args&& ... args)
{
    return [... args = std::forward<Args>(args)]() {(std::cout << ... << args);}
}


//Capture parameter pack by value
template <typename ...Args> auto f1(Args&& ... args)
{
    return [&... args = std::forward<Args>(args)]() {(std::cout << ... << args);}
}

int main()
{
    f1(1,2,3,4,5)();
}