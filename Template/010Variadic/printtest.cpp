#include <iostream>
using namespace std;
int print(int a)
{
    cout <<a<<",";
    return 0;
}

// pack expansion -> only intialize ...

template <typename ...Types> void foo(Types ...args)
{
    //print(args)...// is inot possible
    int x[] {0,print(args)...};
    //empty case
    int x1[] {0,(print(args),0)...};
    initializer_list<int> e= {(print(args),0)...};

}

int main()
{
    foo(1,2,3);

}