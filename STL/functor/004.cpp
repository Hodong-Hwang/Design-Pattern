#include <iostream>
#include <list>
#include <algorithm>
#include "../stltestero.h"


int foo (int a){return a+10;}

int main ()
{
    std::list<int> s1 {1,2,3,4,5};
    std::list<int> s2 {0,0,0,0,0};

    std::transform(begin(s1),end(s1),begin(s2),foo);

    show(s2);
    show(s1);
    std::transform(begin(s1),end(s1),std::back_inserter(s2),foo);
    show(s2);

}