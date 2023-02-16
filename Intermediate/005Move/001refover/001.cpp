#include<iostream>

int main ()
{
    int n=3;
    int& r1 = n; //ok
    int& r2 = 3; // error

    const int& r3 = n; //ok
    const int& r4 = 3; // ok

    int&& r5 = n; // const lvalue는 rvalue와 lvalue 모두 선택..
    int&& r6 = 3; // rvalue reference
}