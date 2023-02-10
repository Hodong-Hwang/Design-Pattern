#include <iostream>
using namespace std;

template <typename ...Types> struct xtuple
{
    static constexpr int N=0;
};

template <typename T, typename ...Types>
struct xtuple <T,Types ...> : public xtuple <Types ...>
{
    T value;
    xtuple() = default;
    xtuple(const T& v, const Types& ...args ):value (v),xtuple<Types ...>(args...) {}
    static constexpr int N=xtuple<Types...>::N+1;
};

template <size_t N, typename TP> struct xtuple_element
{
    typedef TP type;
};

// N==0
template <typename T, typename ...Types> 
struct xtuple_element<0,xtuple<T, Types...>>
{
    typedef T type; // 0번빼 요소 type
    typedef xtuple<T,Types ...> tupleType;
};

// N neq 0

template <size_t N, typename T, typename ...Types> 
struct xtuple_element<N,xtuple<T, Types...>>
{
    typedef typename xtuple_element<N-1,xtuple<Types ...>>::type type;
    typedef typename xtuple_element<N-1,xtuple<Types ...>>::tupleType tupleType;

};

template <size_t N, typename TP>
typename xtuple_element<N,TP>::type& xget(TP& tp)
{
    return  static_cast<typename xtuple_element<N,TP>::tupleType>(tp).value;
} 
// template <size_t N , typename TP>
// xget (TP& tp)
// {
//     return static_cast<TP&>(tp).value;
// }
int main()
{
    xtuple<> t0;
    xtuple <int> t1(3);
    xtuple <int,double,char> t3(1,3.4,'A');
    xtuple_element<0,xtuple <int,double,char> >::type n;
    xtuple_element<2,xtuple <int,double,char> >::type n2;

    cout <<typeid(n).name() <<endl;
    cout <<typeid(n2).name() <<endl;

}