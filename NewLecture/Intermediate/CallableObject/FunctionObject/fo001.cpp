

// Function object , functor
// ()를 사용해서 호출 가능한 객체

#include <iostream>

// 연산자 재정의를 이용함
// a+b = a.operator+(b)
// a-b = a.operator-(b)
// a() = a.operator()() .. 앞에 있는 () 연산자를 의미, 뒤는 ()는 호출하는 의미
// a(1,2) a.operator()(1,2)를 호출하는 것을 ㅎ생각해보면됨.


struct plus
{
    int operator() (int arg1, int arg2)
    {
        
    }
};
