#include <iostream>
#include <compare>

int main()
{
    int n1 = 10, n2=20;
    double d1 = 10, d2=20;

    auto ret1 =(n1<=>n2);
    auto ret2 =(d1<=>d2);
    auto ret3 = (n1<=>d2);

    if(ret1<0){} // ret1 == strong_ordering::less (-1)
    if(ret1>0){}    // ret1==strong_ordering::greater 1
    if(ret1==0){}    // ret1==std::strong_ordering::equal 0
    // 항등연산자를 만들면 != 를 저절로 비교해줌.
    

}