#include <iostream>
#include <algorithm>
#include <functional>

void foo (int a,int b, int c, int d)
{
    printf("%d,%d,%d,%d\n",a,b,c,d);
}

int main ()
{
    std::modulus<int> m;

    //int n = m(10,3); // 10$3;

    int x[5]={9,9,2,4,3};

    // Binary operation is not possible
    //std::find_if(x,x+5,m);

    // we need to reduce uniary operation from binary operator

    std::bind(&foo,10,std::placeholders::_2,std::placeholders::_1,20)(1,2); //10, 2 ,1 20
    std::bind(&foo,std::placeholders::_3,std::placeholders::_2,std::placeholders::_1,100)(30,20,10); //10, 2 ,1 20

    auto p = find_if(x,x+5,std::bind(m,std::placeholders::_1,3));
    std::cout << *p <<std::endl;
}