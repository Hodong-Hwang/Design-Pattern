#include <iostream>
// [first,last)
// 포인터가 아니라도 구간을 표현할 수 잇또록
// type 변환이 가능하도록 구현이 필요함.
// template<typename T>
// T* efinder (T* first, T* last, T value)
// {
//     // T* -> 포인터만 보내야한다는 단점ㅇ ㅣ존재함.
//     while (first!=last && *first !=value)
//     {
//         first++;
//     }
//     return first == last ? 0: first;
// null point 반환을안할 수도 있음. last를 실패로 활용하는 것임.
// }

template<typename T1,typename T2>
T1 efinder (T1 first, T1 last, T2 value)
{
    //concept 검색대상, 검색구간, 구간 표현, 구간 이동(++)
    // 검색 실패시 last return -> 검색 ㅜㄱ간과 관련
    // C++ 컨테이너들은 algorithm을 응용함.
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