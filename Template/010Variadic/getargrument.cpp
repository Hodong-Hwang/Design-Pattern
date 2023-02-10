#include <iostream>
#include <type_traits>
using namespace std;
double hoo(short a, int b) { return 0;}

template <size_t N, typename T> struct argument_type
{
    typedef T type;
};

// template <typename R, typename A1, typename A2> 
// struct argument_type<0,R(A1,A2)>
// {
//     typedef A1 type;
// };

// N ==0
template <typename R, typename A1, typename ...Types> 
struct argument_type<0,R(A1,Types ...)>
{
    typedef A1 type;
};
// 1 -> 0번째 type
// 2 -> N번째 Type

template <size_t N, typename R, 
         typename A1, typename ...Types> 
struct argument_type<N,R(A1,Types ...)>
{
    typedef typename argument_type<N-1,R(A1,Types...)>::type type;
};

/// 3-> 2-> 1->0 ->A1 만 나옴..

template <typename T> void foo(const T& t)
{
    typename argument_type<0,T>::type ret;
    cout <<typeid(ret).name()<<endl;
}


int main()
{

}
