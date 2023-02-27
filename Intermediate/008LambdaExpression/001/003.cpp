#include <iostream>

int main ()
{
    auto f1 =[](int a, int b) -> int {return a+b;};
    auto f2 =[](int a, int b) {return a+b;};

    auto f3 =[](int a, double b) ->double {return a+b;};

}