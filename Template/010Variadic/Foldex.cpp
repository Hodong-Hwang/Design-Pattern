#include <iostream>
#include <tuple>

using namespace std;

template <typename ... Types>
int foo(Types ...args)
{
    int x[]={args...}; //pack exansion
    int n= (args + ...) ; // fold exression
    return n;
}

template <typename ... Types>
void prints(Types ...args)
{
    (cout <<...<<args);
}

int main()
{
    prints(1,2,3,4);
    return 0;
}

