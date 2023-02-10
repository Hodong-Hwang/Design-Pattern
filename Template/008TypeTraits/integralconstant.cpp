#include <iostream>

using namespace std;

template <typename T, T N> struct integral_constants
{
    static constexpr T value = N;
};

// integral_constants<int,0> t0;
// integral_constants<int,1> t1;
// integral_constants<short,0> t3;

typedef integral_constants<bool,true> true_types;
typedef integral_constants<bool,false> false_types;

template <typename T>
struct xis_pointer : false_types
{

};

template <typename T>
struct xis_pointer<T*> : true_types
{

};

template <typename T> void printv_impl (T v,true_types)
{
    cout << v <<":" <<*v <<endl;
}
// int2type is integral_cosntant!!
template <typename T> void printv_impl (T v,false_types)
{
    cout << v<< endl;
}
template <typename T > void printv (T v)
{
    /// if < compile 타임에 결정됨. if(flase) : compile안할래.
    printv_impl(v,xis_pointer<T>());
}
int main()
{
    int n=3;
    printv(n);// error
    printv(&n);
}