#include <iostream>
#include <string>
#include <functional>

// Third Member is Projection
template <class T, class Proj =std::identity>
const T& mymax (const T& obj1, const T& obj2, Proj proj ={})
{
    // std::invoke cna be appiled for.. 
    //return proj(obj1)<proj(obj2) ? obj2 : obj1;
    return std::invoke(proj,obj1)<std::invoke(proj,obj2) ? obj2 : obj1;
}

template <class T>
const T& mymax (const T& obj1, const T& obj2)
{
    return obj1<obj2 ? obj2 : obj1;
}
  

int main ()
{
    std::string s1 = "abcd";
    std::string s2 = "xyz";
    std::identity f;
    auto &r = f(s1);
    std::cout << &s1 <<std::endl;
    std::cout << &r <<std::endl;
    auto ret1 = mymax(s1,s2);
    auto ret2 = mymax(s1.size(),s2.size());

    // binary and unary operator can be used.. 
    // auto ret3 = mymax(s1,s2,[](auto& a, auto& b){return a.size()<b.size();});
    //auto ret4 = mymax(s1,s2,[](auto& a){return a.size();});
    auto ret5 = mymax(s1,s2,&std::string::size);

    // binary operator woudl be used for comarpsion 

    std::cout << ret5 << std::endl;
}