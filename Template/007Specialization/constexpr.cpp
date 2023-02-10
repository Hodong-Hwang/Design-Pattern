#include <iostream>
using namespace std;
template<int N> struct check{};

constexpr int add (int a, int b)
{
    return (a+b);
}

int main ()
{
    int n= add(1,2);
    check <add(1,2)> c;
    int n1= 1, n2=2;
    add(n1,n2);
    //check <add(n1,n2)> c;

}