
#include <iostream>
using namespace std; 

template <typename ... Types> class tuples
{
    
};

// void goo(int n, double d ,const char* s)
// {
//     cout <<"goo : "<< n << " " << d<< " " << s << endl; 
// }
void goo(int a, int b, int c)
{
    printf("a=%i,b=%i,c=%i\n",a,b,c);
}
int hoo (int a) {return -a;}
template <typename ...Types>
void foo(Types... args)
{
    //int x[] = {(++args)...} ; // -> 파라미터 팩을 사용하는 패턴
    int x[]={hoo(args)...}; //ok

    for (auto n:x)
    {
        cout << n <<endl;
    }
    goo(args...);// ok
    //goo(hoo(args...))// error
    goo(hoo(args)...);//ok
    //hoo(args...);// error
    // cout << sizeof...(args)<<endl;
    // cout << sizeof...(Types)<<endl;
    // // goo(args); error
    // goo(args...);// pack expansion ... -> goo(arg1,arg2,arg3 ...)

}

int main()
{
    foo(1,2,3);
    
    return 0;
}