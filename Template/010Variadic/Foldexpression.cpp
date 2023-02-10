#include <iostream>
#include <type_traits>
using namespace std;


double hoo(short a, int b) { return 0;}

template <typename T> struct result_types; // 의도적 선언만 
// {
//     // typedef T type; // type 타입 지정 ㄴㄴ
//     // static_assert(is_function<T>::value,"T type is not function"); // static assert 이용
// };

template <typename R,typename ... Types> 
struct result_types<R(Types ...)>
{
    typedef R type;
};
// primary template
template <typename T> void foo(const T& t)
{
    typename result_types<T>::type ret;
    cout<<typeid(ret).name() <<endl;
}

int goo() {return 0;}
int main()
{
    foo(goo);
    foo(1);
}

