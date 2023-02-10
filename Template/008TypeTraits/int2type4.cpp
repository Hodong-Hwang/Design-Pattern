#include <iostream>
using namespace std;

template <int N > struct int2type
{
   static constexpr int value= N;
};

template <typename T> struct xis_pointer
{
   static constexpr bool value =false;
};
template <typename T> struct xis_pointer <T*>
{
   static constexpr bool value =true;
};
template <typename T> void printv_impl (T v,int2type<1>)
{
    cout << v <<":" <<*v <<endl;
}
// int2type is integral_cosntant!!
template <typename T> void printv_impl (T v,int2type<0>)
{
    cout << v<< endl;
}
template <typename T > void printv (T v)
{
    /// if < compile 타임에 결정됨. if(flase) : compile안할래.
    printv_impl(v,int2type<xis_pointer<T>::value>());
}

int main()
{
    int n=3;
    printv(n);// error
    printv(&n);
}