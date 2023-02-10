#include <iostream>
using namespace std;

// template meta progmraming -> compile 타임을 이ㅛㅇ한 프로그래밍.
template <int N> struct factorial
{
    // enum {value =N*factorial<N-1>::value};
    static constexpr int value = N*factorial<N-1>::value;
};

template <> struct factorial<1>
{
   // enum {value=1};
    static constexpr int value=1;

};
// 현재에는 c++ constexpr을 이용함.
int main ()
{

    int n = factorial<5>::value;
    cout << n << endl;
}