
#include <iostream>
#include <vector>
using namespace std;

// template <typename T> char check (typename T::value_type* a);
// template <typename T> short check (...);


template <typename T> 
struct has_value_type
{
    static constexpr bool value_type (sizeof (check<T>(0))==1);
};

/// @brief  임시 객체를 만들어야 하는 단점이 있음.
/// @tparam T 
/// @param a 
/// @return 
template <typename T> char check (decltype(T().resize(0))* a);
template <typename T> short check (...);

template <typename T> 
struct has_resize
{
    static constexpr bool value_type (sizeof (check<T>(0))==1);
};



int main ()
{
    cout << has_resize<vector<int>>::value <<endl;
}