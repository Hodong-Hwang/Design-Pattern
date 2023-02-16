
// 변환 연산자, 변환 생성자, explicit 생성자
// safe bool 개념, eplicit 변환 연산자.
// nullptr, temporary proxy

#include <iostream>
//변환 연산자 0> 객체가 다른타입으로 변환될 때 호출되는 함수.

class Int32
{
    int value ;
    public:
    Int32() :value (0){}
    Int32(int n) :value (n){}

    operator int() const {return value;}
    Int32 (const Int32&)=delete;
    Int32& operator =(const Int32&)=delete;

};

int main()
{
    int pn;
    Int32 un;
    pn = un; // un.operator int()
    un = pn; // pn.operator Int32();
    // 1. unoperator=(pn)
    // 2. Int32(pn);

}