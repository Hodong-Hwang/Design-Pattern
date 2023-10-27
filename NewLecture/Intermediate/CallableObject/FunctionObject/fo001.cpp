

// Function object , functor
// ()를 사용해서 호출 가능한 객체
// intent :
// 특정 상황에서 함수보다 빠르다.
// 상태를 가질 수 있따.
// 객체는 자신만의 타입을 가지는 것이다.

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
        return arg1 + arg2;
    }
};


int main()
{
    plus p;
    int n = p(1,2); // p.operator()(1,2)

    std::cout << n <<std::endl;
}