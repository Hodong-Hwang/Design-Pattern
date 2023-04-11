#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool foo (int a) {return a%3==0;}
int main ()
{
    vector<int> v={6,9,3,1,2};

    auto p  = find(begin(v),end(v),3);

    auto p1 = find_if(begin(v),end(v),foo);
    auto p2 = find_if(begin(v),end(v),[](int a){return a%3==0;});

    // remove,
    // remove_if
    // remove_copy p2 pointer
    // remove_copy_if


}