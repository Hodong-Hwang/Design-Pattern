#include <iostream>

int main ()
{
    auto f1 =[] (int a,int b){return a+b;};
    int(*f)(int,int)=[] (int a,int b){return a+b;}; //변환 연산자가 필요함. invoke를 통해서 정함.

}