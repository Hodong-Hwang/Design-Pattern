#include <iostream>
#include <type_traits>
template <bool b, typename T = void> struct enable_if
{
};

template <typename T > struct enable_if<true,T>
{
    typedef T type;
};

// 정수일때만 함.
// template <typename T> void foo(T a)
// {
//     static_assert(std::is_integral<T>::value,"error");
// };

template <typename T>
typename enable_if<std::is_integral<T>::value>::type
foo(T a)
{
    std::cout <<"T" << a <<std::endl;
}
void foo(...)
{
    std::cout << "not Integer"<<std::endl;
}

void ex()
{
    foo(3);
    foo(3.14);
}
///  1. enable if 위치는 -> 함수 리턴타입
///  2. 함수 인자타입 => 생성자에서 주로 사용함.
///  3. 템플릿 인자 -> 함수 자체모양이 단순해짐.
int main ()
{
    // enable_if<true, int>::type t0;
    ex();
    // Error Beacuse of it has no type;
    //enable_if<false, int>::type t1;

}
