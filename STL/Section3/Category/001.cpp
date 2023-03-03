#include <forward_list>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

template <typename T>
void eadvance (T& p , int n)
{
    while (n--) 
        ++p; // 성능 저하 (vector의 경우)
}


int main ()
{
    vector <int> v={1,2,4,5,76,8,990,9,6,74};
    vector <int> v2(14);
    std::iota(v2.begin(),v2.end(),0);

    for (auto& n : v2)
    {
       cout << n << "," ;
    }
    auto p = begin(v);
    advance(p,5);



}