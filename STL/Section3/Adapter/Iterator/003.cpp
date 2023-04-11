#include <iostream>
#include <list>
#include <algorithm>

using namespace std;


int main ()
{
    list<int> s ={1,2,3,4,5,6,7,8,9,10};


    auto p1 = begin(s);
    auto p2 = end (s);
    auto r2 = std::make_reverse_iterator(p2);
    auto r3 = s.rbegin();
    auto r4 = std::rbegin(s);

    auto ret= find (rbegin(s),rend(s),3);
    

}