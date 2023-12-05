#include <iostream>
#include <string>

template <class T>
const T& mymax(const T& obj1, const T& obj2)
{
    return obj1<obj2 ? obj2 : obj1;
}   

int main ()
{
    std::string s1="abcd";
    std::string s2 = "xyz";


    auto ret1=mymax(s1,s2);
    auto ret2=mymax(s1.size(),s2.size());
    // 이항조건을 받자., 단항조건자사용
    // 두가지 모두 사용하는 것 (C++ 20에서부터 가능함.)
    // 3번쨰 인자로 크기비교를 이용할 것.
    // callalble
}