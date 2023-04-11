#include <iostream>
#include <iterator>
#include <forward_list>

using namespace std;
int main ()
{
    int x[10]{1,2,3,4,5,6,8,9,0};
    std::forward_list<int> s{1,2,3,4,5,6,8,9,0};

    // pointer는 ++이 안됨.
    auto p1 = next(begin(x));
    advance(p1,3);

    auto p2 = next(begin(s));
    advance(p2,3);
   // prev(p2);
    std::cout << *p1 <<std::endl;

    std::cout <<distance(begin(x),p1)<<std::endl;
    std::cout <<distance(begin(s),p2)<<std::endl;

}