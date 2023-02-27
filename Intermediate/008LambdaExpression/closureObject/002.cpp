#include <iostream>

int main ()
{
    int v1 = 10 , v2 = 20;
    //auto f =[v1,v2](int a){v1=a;v2=a;}; ->const 생성
    auto f =[v1,v2]  (int a)mutable{v1=a;v2=a;};

    // compiler geneated anme (class 를 생성)

    
}