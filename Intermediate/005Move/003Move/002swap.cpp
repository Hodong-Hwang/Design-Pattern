#include <iostream>
#include <string>

template<class T>
void swap1(T& lhs,T& rhs)
{
    T tmp = lhs;
    lhs =rhs;
    rhs =tmp; // 3번의 memory 복사가 발생함.
}

template<class T>
void swap2(T& lhs,T& rhs)
{
    // 주소 3번의 복사를 이용함.
    T tmp = std::move(lhs);
    lhs =std::move(rhs);
    rhs =std::move(tmp); // 3번의 memory 복사가 발생함.
}

int main ()
{
    std::string s1="s1";
    std::string s2 = "s2";
    swap2(s1,s2);
    std::cout <<s1 <<std::endl;
    std::cout <<s2 <<std::endl;

}