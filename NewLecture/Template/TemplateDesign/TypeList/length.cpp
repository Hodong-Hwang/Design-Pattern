#include <iostream>

template <typename T, typename U> struct Typelist
{
    typedef T Head;
    typedef U Tail;
};

struct NullType
{
};

// 선형화를 위한 Macro 도입
#define TYPELIST_1(T1) Typelist<T1,NullType>
#define TYPELIST_2(T1,T2) Typelist<T1,TYPELIST_1(T2)>
#define TYPELIST_3(T1,T2,T3) Typelist<T1,TYPELIST_2(T2,T3)>
#define TYPELIST_4(T1,T2,T3,T4) Typelist<T1,TYPELIST_3(T2,T3,T4)>
// 사용하는 모습을 보고 primary template을 작성함
template <typename T> struct length;

//Length를 사요할 수 있도록 부분 특수화를 해주어야함.
template < typename T, typename U> struct length<Typelist<T,U>>
{
    enum {value =length<U>::value +1};
};
// 재귀 종료 선언

template <> struct length<NullType>
{
    enum{value = 0};
};

template <typename T>
void get_length()
{
    std::cout <<length<T>::value <<std::endl;
}
int main()
{
    get_length<TYPELIST_4(double,int,char,int)>();
    std::cout <<length<TYPELIST_4(double,int,char,int)>::value <<std::endl;
}