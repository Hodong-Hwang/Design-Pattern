#include <iostream>

class X{};

//void foo(X x) { std::cout << "X" <<std::endl;} // error
// 객체를 수정하겠다. lvaue를 주어야함.
void foo(X& x) { std::cout << "X&" <<std::endl;} //1
// const X& x 는 객체만 읽겠다는 의도. l + r!! 모두 가능
void foo(const X& x) { std::cout << "const X& " <<std::endl;} //2
// MoveSemantic을 사용하겠다는 의도가 있음.
// rvalue를 받겠다느 ㄴ의미가 있음.
void foo(X&& x) { std::cout << "X&&" <<std::endl;} //3

// const X&& x는 문법적으로는 의미가 없다.
//void foo(const X&& x) { std::cout << "const X&&" <<std::endl;}
// 오버로딩 규칭
// 값 타입과 참조 타입은 오버로딩 될 수 없다.
int main ()
{
    X x;
    foo(x);  // lvaue 는 1번이 우선시 1번이 없는 경우 2번으로 
  
    foo(X()); //3 번이 없으면 2번으로 감.

    X&& rx = X(); //temoprarly -> rx는 의미가 있음
    //rx는 lvalue가 됨. rx의 data type은 rvalue임. 
    foo(rx);  // 1번으로감

    // 3번으로 보내기 위해서 lvalue를 rvalue로 보내주어야함
    foo(static_cast<X&&>(rx)); // value를 변환하는Cast에 해당함.
    return 0;
}