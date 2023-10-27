#include <iostream>
#include <vector>
#include <array>
struct NoValueType
{
};

struct HasValueType
{
    typedef int value_type;
};

// 선언부를 조사해서 decltype을 조사함.
template <typename T>  char check( decltype(T().resize(0))* );

// 함수 return size 2
template <typename T> short check(...);


template <typename T> struct has_resize
{
    static constexpr bool value = (sizeof(check<T>(0))==1);
};

// 여기서 문제가 T(). 생성자가 없는경우 사용할 수 없다는 단점이 있음.
// 이를해결하는 방법으로 C++11에 표준에 정의되어있음.
int main()
{
    std::cout << has_resize<std::vector<int>>::value <<std::endl;
    std::cout << has_resize<std::array<int,10>>::value <<std::endl;
}