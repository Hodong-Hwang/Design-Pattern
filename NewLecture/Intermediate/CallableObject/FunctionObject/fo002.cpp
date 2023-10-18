#include <iostream>

template <class T>
struct plus
{
    [[nodiscard]] constexpr 
    T operator() (const T& arg1, const T& arg2) const
    {
        return arg1 + arg2;
    }
};


int main()
{
    const plus<int> p;
    int n = p(1,2); // p.operator()(1,2)
    p(3,4);
    std::cout << n <<std::endl;
}