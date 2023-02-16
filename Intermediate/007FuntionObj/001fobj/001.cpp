#include <iostream>

struct plus
{
    int operator () (int arg1,int arg2)
    {
        return arg1+arg2;
    }
};

//괄호를 사용해서 호출가능한 핵체 functor, function objector

int main()
{
    plus p;
    int n = p(1,2);

    std::cout << n <<std::endl;
}

