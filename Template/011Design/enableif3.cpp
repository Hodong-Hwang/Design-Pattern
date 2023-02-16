#include <iostream>
#include <type_traits>


using namespace std;

// template <typename T> void printv(const T& v)
// {
//     if constexpr(is_pointer<T>::value)
//     {
//         cout << v <<" : " << *v <<endl;
//     }
//     else
//     {
//         cout << v <<endl;
//     }
// }

// SIFANE으 ㅣ응용
template <typename T> 
typename enable_if<is_pointer<T>::value>::type 
printv(const T& v)
{

    cout << v <<" : " << *v <<endl;
}

template <typename T> 
typename enable_if<!is_pointer<T>::value>::type 
printv(const T& v)
{

    cout << v <<endl;
}

/// @brief  
/// 1. Type traits-> + if constexpr
/// 2. type_triats + bool_type
/// 3. enable if -> return type d
/// @return 
int main ()
{
    int n = 0;
    printv(n);
    printv(&n);
}