#include <iostream>

int main ()
{
    int v1 = 10 , v2 = 20;
    auto f =[v1,v2](int a){return a+v1+v2;};
    // compiler geneated anme (class 를 생성)
    std::cout <<f(5)<<std::endl;
    std::cout <<sizeof(f) <<std::endl;

    return 0;
}