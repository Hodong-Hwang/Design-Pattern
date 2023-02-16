
#include <iostream>

int x= 0 ;

int foo (int a,int b){return 0;}
int& goo (int a, int b){return x;}

int main()
{
    decltype(foo) d1 ; // int (int,int)
    decltype(foo(1,2)) d2 ; // int

    // unevalueated expression is very important
   // decltype(goo(1,2)) d3 ; // int& 참조인 데 초기값이 없ㅇ므.

   auto ret1 = goo (1,2); // int ret1=goo(1,2);
   decltype(goo(1,2)) ret2 =goo(1,2); // ->int&
   decltype(auto) ret = goo (1,2);// decltype을 넣어서 결정해줘야함.

}