#include "typeid.h"
#include <iostream>
#include <typeinfo>
template <typename T>
void print_typeof (T const& x)
{
    std::cout << typeid(x).name() << std::endl;
}

template void print_typeof<double>(double const&);
void ex1()
{
    double ice = 3.0;
    print_typeof(ice); // call function template for type double
}
int main()
{

    ex1();
    return 0;
}