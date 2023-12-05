#include <iostream>
#include <functional>
template <class T,class Proj=std::identity >
const T& mymax(const T& obj1, const T& obj2, Proj proj)
{
    return std::invoke(proj,obj1)<std::invoke(proj,obj2) ? obj2 : obj1;
}   



int main ()
{
    std::string s1="abcd";
    std::string s2 = "xyz";


    auto ret1=mymax(s1,s2,[](auto& a){return a.size()});
    auto ret2=mymax(s1,s2,[](auto& a){return &std::string::size});

    std::identity f;
    auto& r = f(s1);// 반환 값으로 그참조가 나옴.
    // s1과 r은 같은 주소를 가짐.
    // 이항조건을 받자., 단항조건자사용
}