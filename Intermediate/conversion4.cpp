#include <iostream>
struct Alloc
{
    size_t size;
    Alloc(size_t sz): size(sz){}
    template <class T>
    operator T*() {return new T[size];}
};


int main()
{
    int* p1 =Alloc(10);
    double *p2 = Alloc(10);
    auto f1 = [] (int a, int b){return a+b;};
    int(*f2) (int ,int )=[](int a, int b) {return a+b;};
    // 임시객체 .opeartor () 함수 포인터 ()
}