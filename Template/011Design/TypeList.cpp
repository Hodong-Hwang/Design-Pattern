#include <iostream>

template <typename T, typename U> struct Typelist
{
    typedef T Head;
    typedef U Tail;
};

struct NullTypes{};
// 사용하는 모습을 보고 primary template을 구하여함.
template <typename T> struct Length;

template <typename T, typename U> 
struct Length<Typelist<T,U>>
{
    enum {value=Length<T>::value+1 };
};

template <> 
struct Length<NullTypes>
{
    enum {value=0};
};
#define TYPELIST_1 (T1) Typelist<T1,NullTypes>
#define TYPELIST_2 (T1,T2) Typelist<T1,Typelist<T2,NullTypes>>
#define TYPELIST_3 (T1,T2,T3) Typelist<T1,Typelist<T2,Typelist<T3,NullTypes>>>
#define TYPELIST_4 (T1,T2,T3,T4) Typelist<T1,Typelist<T2,Typelist<T3,Typelist<T4,NullTypes>>>>

template <typename T> void Test()
{
    std::cout <<
    Legnth<test<TYPELIST_4(int,char,short,double)>>::value
    <<std::endl;
}

int main()
{
    return 0;
}