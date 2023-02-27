#include <iostream>

int main ()
{
    int v1 = 10 , v2 = 20;
    //auto f =[v1,v2](int a){v1=a;v2=a;}; ->const 생성
    auto f =[&v1,&v2]  (int a) {v1=a;v2=a;}; // v1이 가리키는 곳을 바꾸기 때문에 수정이 가능함.
    f(3);
    std::cout << v1 << std::endl;

    // compiler geneated anme (class 를 생성)

    
}