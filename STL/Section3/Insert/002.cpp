#include <iostream>
#include <list>
#include <numeric>
#include <iterator>

template <typename T>
std::back_insert_iterator<T>
back_inserters(T& c)
{
    return std::back_insert_iterator<T>(c);
}

int main ()
{
    std::list<int> s(5);
    std::iota(s.begin(),s.end(),0);    
    int x[5];
    std::iota(std::begin(x),std::end(x),10);

    std::copy(x,x+5,back_inserters(s));

    for (auto& n : s )
    {
        std::cout << n << ",";
    }

    std::cout <<std::endl;
}