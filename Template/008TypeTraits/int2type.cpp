#include <iostream>
using namespace std;
// int2type은 독립된 형태로 만들 어 줄 수 있음

template <int N > struct int2type
{
   static constexpr int value= N;
};


// 활용 방안.
template <typename T> struct xis_pointer
{
   static constexpr bool value =false;
};
template <typename T> struct xis_pointer <T*>
{
   static constexpr bool value =true;
};

template <typename T > void printv (T v)
{
    /// if < compile 타임에 결정됨. if(flase) : compile안할래.
    if constexpr( xis_pointer<T>::value)
    {
        cout << v << ":" <<*v<< endl;
    }
    else
    {
        cout<< v<<endl;
    }
}

int main()
{
    int n=3;
    printv(n);// error
    printv(&n);
}