#include <iostream>

//C++ 20부터 lamda 가능.
auto add(auto a, auto b)
{
    return a+b;
};

int main()
{
    //auto add =[](int a, int b) {return a+b;};
    // generic lambda expression
    auto add =[](auto a, auto b) {return a+b;};

    std::cout <<add(1,1) <<std::endl;
    std::cout <<add(1,1.2) <<std::endl;
    std::cout <<add(1.2,1.4) <<std::endl;
    // Clousre Type으로 만들어 줌.
    //template으로 만들ㅇ거줌.
    // 자동으로 instance화 하는 것이 특징임
    // template <typename T1, typename T2>


}