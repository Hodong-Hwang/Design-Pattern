#include <iostream>

//forwarding reference ..

void f1(int& arg){}
void f2(int&& arg){}

template <typename T> void f3(T& arg){};

//T -> 참조가 있으면 collapsing 규칙을 적용.

int main ()
{
    int n = 0;
    f1(n);
//    / f1(0); //error

    f3(n); // ok
    f3(0); //error
    f3<int>(n); // T int
    f3<int&>(n); // T int&
    f3<int&&>(n); // T int&^ collapsing 규칙을 적용.
    f3(0);

}