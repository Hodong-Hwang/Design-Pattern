#include <iostream>
#include <vector>
using namespace std;

template<typename T, int N> struct arrays
{
    T buf[N];
    typedef T* iterator ;
    iterator begin() {return buf;}
    iterator end() {return buf+N;}
    int size() const {return N ;}
    T& operator[](int n){return buf[n];}
};

int main ()
{
    int x[5];
    arrays<int,5> arr={1,2,3,4,5};

    cout <<arr.size() <<endl;

}