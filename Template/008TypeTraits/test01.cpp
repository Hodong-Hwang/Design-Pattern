#include <iostream>
using namespace std;

// type_tarits 제공..  
// 어떻게 만드는지 
template <typename T> struct xis_pointer
{
    enum{value =false};
};
template <typename T> struct xis_pointer <T*>
{
    enum{value =true};
};

template <typename T > void printv (T v)
{
    if ( xis_pointer<T>::value)
    {
        cout << "Pointer"<< endl;
    }
    else
    {
        cout << "is not Pointer"<< endl;
    }
}

// template <typename T > void printv (T v)
// {
//     if ( T is Pointer)
//     {
//         cout <<v << ":" <<* v << endl;
//     }
//     else
//     {
//         cout <<v  << endl;
//     }
// }

int main ()
{
    int n =3;
    double d =3.4;
    printv(n);
    printv(d);
    printv(&d);
}