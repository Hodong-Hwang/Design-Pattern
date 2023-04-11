#include <iostream>
#include <list>
#include <algorithm>

using namespace std;


int main ()
{
    list<int> s ={1,2,3,4,5,6,7,8,9,10};


    auto p1 = begin(s);
    auto p2 = end (s);
    reverse_iterator<std::list<int>::iterator> p3 (p2);
    reverse_iterator<std::list<int>::iterator> p4 (p1);
    p3++;
    
    cout << *p3 <<endl;

    auto ret1= find(p3,p4,3);
}