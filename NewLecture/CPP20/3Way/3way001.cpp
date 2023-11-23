#include <iostream>
// spaceship operator
int main()
{
    int a=10, int b=20;
    auto ret1 =a<=>b; // spaeceship operator
    // type의 이름ㅇ.ㅡㄴ
    // storng ordering, weak, partial...
    std::cout << typeid(ret1).name() <<std::endl;
}