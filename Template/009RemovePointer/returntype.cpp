#include <iostream>
using namespace std;

double hoo (short a, int b) {return 0;}

template <typename T> struct result_type
{
    //typedef T type; //error ->(컴파일 에러 발생을 위해 비활성화)
};

template <typename R, typename A1, typename A2> 
struct result_type<R(A1,A2)>
{
    typedef R type;
};


// template <typename T,typename A1,typename A2, size_t N>
// struct argument_Type<R(A1,A2),N>
// {
//     typedef T type;
// };

template <typename T, size_t N>
struct argument_Type
{
    //typedef T type;
};
template <typename R,typename A1,typename A2>
struct argument_Type<R(A1,A2),0>
{
    typedef A1 type;
};
template <typename R,typename A1,typename A2>
struct argument_Type<R(A1,A2),1>
{
    typedef A2 type;
};


template <typename T> void foo(T& t)
{
    typename result_type<T>::type ret;
    typename argument_Type<T,0>::type arg;
    typename argument_Type<T,1>::type args;

    cout<<typeid(ret).name() <<endl;
    cout<<typeid(arg).name() <<endl;
    cout<<typeid(args).name() <<endl;

}

int main()
{
    foo(hoo);

    return 0;

}