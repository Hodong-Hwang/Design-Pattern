#include <iostream>
#include <type_traits>

/// @brief  C++ 20에서는 조사식에 explicit 조건문이 붙을 수있음.
/// @tparam T 
template <typename T>
class Number
{
    T value ;
    public :
    explicit (!std::is_integral<T>)
    Number(T v):value (v){}
};

int main()
{
    Number n1 = 10;
    // Number n2 =3.4;
}