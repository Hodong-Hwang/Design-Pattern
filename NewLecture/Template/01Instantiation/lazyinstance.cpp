#include <iostream>
template <typename T>
class A
{
    T data;
    public :
    void foo(T n) {*n=10;} // error ->사용되지 않는 변수들은 생성하지 않음.
};

struct Resource1
{
    Resource1() {std::cout <<"Resource1"<<std::endl;}
};
struct Resource2
{
    Resource2() {std::cout <<"Resource2"<<std::endl;}
};

template <typename T> struct Test
{
    Resource1 res1;
    static Resource2 res2;
};

template <typename T>
Resource2 Test<T>::res2; // 메모리에 잡히는가?
// 해당 메모리는 사용되지 않아서 메모리에 잡히지 않음,
// 사용하지 않으면 인스턴스화가 되지 않음.

int main()
{
    std::cout <<"main" <<std::endl;
}