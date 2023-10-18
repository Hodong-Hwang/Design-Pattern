#include <iostream>

int main()
{
    int v1= 10,v2=20;

    auto f = [v1,v2](int a) mutable {v1=a ,v2=a;};
    f(3);

    std::cout << v1 << std::endl;

    // 임시 맴버 함수의 멤버 변수가 바뀐 값임. 
    std::cout <<f.__v1 <<std::endl;


}