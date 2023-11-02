#include <iostream>
class Int32
{
    int value;
public:
    Int32(): value(0){}
    Int32(int n): value(n){}

   // operator int () {return value;}
    // 변환 연산자 만들 때 상수 객체도 고려해주어야함.
    operator int () const {return value;}

};

// primitive type하고 호환하도록

int main()
{
    int pn;
    Int32 un;
    // pn=un; 변환이 없음
    // .. un.operator int() 값을 찾음.
    // 우리는 변환연산자 operator type() 을 찾아야함.
    // return type을 표기하지 않음.
    
    // case 2 반대인 경우
    // un = pn; pn.operator Int32() 불가능
    //  없는 경우 다음을 찾아.
    // 1. un. operator =(pn)
    // 2. Int32(pn)? default 대입 연산자를 이용함.
    //

    un=pn;
}