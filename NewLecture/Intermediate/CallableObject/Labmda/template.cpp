#include <iostream>


int main()
{
    int n1=10;
    int n2=20;
    double d1 = 1.1;
    double d2 = 1.2;


    auto swap =[](auto& a, auto& b){auto tmp=a; a=b; b=tmp;};
    swap(n1,d2); // -> error 발생해야하는데 하지 않음.

    //template swap
    auto safe_swap = []<typename T> (T&a, T&b){auto tmp =a; a=b; b=tmp;};
    safe_swap(n1,n2);
    

}