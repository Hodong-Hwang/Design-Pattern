
#include <iostream>
using namespace std; 

template <typename ... Types> class tuples
{
    
};

void goo(int n, double d ,const char* s)
{
    cout <<"goo : "<< n << " " << d<< " " << s << endl; 
}

template <typename ...Types>
void foo(Types... args)
{
    cout << sizeof...(args)<<endl;
    cout << sizeof...(Types)<<endl;
    // goo(args); error
    goo(args...);// pack expansion ... -> goo(arg1,arg2,arg3 ...)

}

int main()
{
    // tuple <> t0;
    // tuple <int> t1;
    // tuple <int,char> t2;
    foo(1,3.4,"AAA");
    return 0;
}