#include <iostream>
template<unsigned N>
struct fibonacci{
    static const unsigned value = fibonacci<N-1>::value + fibonacci<N-2>::value;
};
template<>
struct fibonacci<1>{
    static const unsigned value = 1;
};
template<>
struct fibonacci<0>{
    static const unsigned value = 0;
};


int main()
{
    std::cout << fibonacci<10>::value <<std::endl;
}