#include <functional>
class X
{
    public:
        void mf1(int a){}
        static void mf2(int a){}
};


void foo(int a)
{}


int main()
{
    void(*f1)(int)=&foo; //ok
    //void(*f2)(int)=&X::mf1; //ok -> imposilble void mf (X* this, d)
    void(*f3)(int)=&X::mf2; //ok
    //일반함수의 포인츠는 static을 가능함

    //함수포인터
    void(X::*f2)(int)=&X::mf1; // 멤버함수 포인터 -> &X::mf1;
    //함수의 주소를 얻는것
    f1(10);// okay
    //f2(10); //객체가 없음.
    X obj;
    //obj.f2(10); // Error f2라는 멤버를 찾게됟나.
    // d이때사용할 수 잇는 방법이 pointer to memeber
    // 연산자 우선순위로 에러 obj.*f2(10);
    (obj.*f2)(10); //연산자 우선순위 변경
    // f2(&obj,10); // uniform call syntax -> 채택 안됨
    // 이거 대신에 사용되는게 invoke functional
    // std::invoke(함수 포인터, 함수 인자들)

    std::invoke(f1,10);
    std::invoke(f2,obj,10);
    std::invoke(f2,&obj,10);
    // invoke는 callable object를 호출할 수 잇음.

    auto f4=std::mem_fn(&X::mf1);
    f4(obj,10);

}