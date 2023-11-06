#include <iostream>
// finder 에 list와 array가 모두 적용가능하도록 변경
template<typename T1,typename T2>
T1 efinder (T1 first, T1 last, T2 value)
{
    // *역참조
    // ++ 이동이 가능해야함.
    // 비교연산이 가능해야함.
    // 이러한 연산이 가능하도록 하는 것임 Iterator임!!!
    while (first!=last && *first !=value)
    {
        first++;
    }
    return first; 
}
int main()
{
    double d[10]{1,2,3,4,5,6,7,8,9,10};
    double* p =efinder(d,d+10,5); // 함수는 인자를 알아서 추정함.


    if( p==0)
    {
        std::cout << "fail" << std::endl;
    }
    else
    {
        std::cout <<"sucess : " << * p <<std::endl;
    }
}