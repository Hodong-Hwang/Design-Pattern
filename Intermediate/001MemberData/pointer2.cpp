#include <functional>
class X
{
    public:
    void mf1(int a){}
    static void mf2( int a) {}
};


void foo(int a){}
int main(){
    void(*f1)(int) = &foo;


    void(X::*f2)(int) = &X::mf1; // void (mf1(x* this, int a))

    // pointer to member
    f1(10);

    X obj;
    (obj.*f2)(10); //error // 연산자 우선순위 문제
    // function pointer 함수 인자들
    std::invoke(f1,10);
    std::invoke(f2,obj,10);
    std::invoke(f2,&obj,10);


}