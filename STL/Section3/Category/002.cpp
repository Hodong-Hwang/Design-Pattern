#include <forward_list>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

// dispatching을 이용

struct einput_iterator_tag{}; //empty class 
struct eoutput_iterator_tag{};

struct eforward_iterator_tag
:public einput_iterator_tag{};

struct ebidirectional_iterator_tag : public eforward_iterator_tag
{};

struct erandom_access_iterator_tag: public ebidirectional_iterator_tag {};


// 반복자를 만들때
template <typename T> class vector_iterator
{
    public: 
    using iterator_category = ebidirectional_iterator_tag;


};

template <typename T>
void eadvance_imp (T& p , int n,random_access_iterator_tag)
{
    p=p+n;
    cout << "random Accesoble" <<endl;
}

template <typename T>
void eadvance_imp (T& p , int n,input_iterator_tag)
{
    while (n--)  ++p; // 성능 저하 (vector의 경우)
    cout << "input Accesoble" <<endl;

}

template <typename T>
void eadvance (T& p , int n)
{
    // T::iterator_category 
    eadvance_imp(p,n,typename T::iterator_category());
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
    cout << endl;
    auto p = begin(v);
    eadvance(p,5);



}