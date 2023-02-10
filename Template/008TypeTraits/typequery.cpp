#include <iostream>
#include <type_traits>
using namespace std;

template <typename T>
void foo_impl( T v , true_type)
{

}
template <typename T> 
void foo_impl( T v , false_type)
{

}
template <typename T> void foo(T v)
{
    // T 
    if constexpr(is_pointer<T>::value)
    {
        *v=10;
    }
    foo_imp(v,is_pointer<T>());
}