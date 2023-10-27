#include <iostream>
struct NoValueType
{
};

struct HasValueType
{
    typedef int value_type;
};

// 함수 return size 1
template <typename T>  char check(typename T::value_type* a);

// 함수 return size 2
template <typename T> short check(...);


template <typename T> struct has_value_type
{
    static constexpr bool value = (sizeof(check<T>(0))==1);
};


int main()
{
    // bool b1 = has_value_type<NoValueType>::value ;// flase
    // bool b2 = has_value_type<HasValueType>::value ;// flase
    //HasValueType t1; check(t1)
    // std::cout << sizeof(check<HasValueType>(0))<<std::endl;
    // std::cout << sizeof(check<NoValueType>(0))<<std::endl;
    std::cout << has_value_type<HasValueType>::value<<std::endl;
    std::cout << has_value_type<NoValueType>::value<<std::endl;
    //NoValueType t2; check(t2);

}
