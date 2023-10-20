#include <iostream>
#include <type_traits>

// 정수일 때만 함수 코드를 생성한다.
// template <typename T> void foo(T a)
// {
//     static_assert(std::is_integral<T>::value,"error");
// }


// 정수가 아닐 때 다른 함수를 실행하도록
// 즉 조건을 만족할 때만 해당  함수를 사용함.
template <typename T> 
std::enable_if<std::is_integral<T>::value>::type
foo(T a)
{
    std::cout <<3 <<std::endl;

}

void foo(...)
{
    std::cout <<"..." <<std::endl;
}
int main()
{
    foo(3.4);
    foo(3);
}