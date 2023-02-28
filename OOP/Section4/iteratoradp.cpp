#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main ()
{
    list <int> s ={1,2,3,4};

    auto p1=s.begin();
    auto p2 =s.end();
    reverse_iterator<list<int>::iterator> p3(p2);
    reverse_iterator<list<int>::iterator> p4(p2);


    for_each(p1,p2,[](int a){cout << a <<endl;});
    for_each(p3,p4,[](int a){cout << a <<endl;});

    return 0; 
};

