

#include <iostream>
#include <list>
#include <numeric>
#include <iterator>

int main ()
{
    std::list<int> s(5);
    std::iota(s.begin(),s.end(),0);
    s.push_back(10);
    std::back_insert_iterator<std::list<int>> p (s);
    
    int x[5];
    std::iota(std::begin(x),std::end(x),10);

    std::copy(x,x+5,p);

    for (auto& n : s )
    {
        std::cout << n << ",";
    }

    std::cout <<std::endl;
}