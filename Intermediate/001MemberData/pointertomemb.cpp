
class X
{
    public:
    void mf1(int a){}
    static void mf2( int a) {}
};


void foo(int a){}
int main(){
    void(*f1)(int) = &foo;

   // void(*f2)(int) = &X::mf1; Error

    void(X::*f2)(int) = &X::mf1; // void (mf1(x* this, int a))
    //일반 함수에 멤버 함수의 주소를 담을 수 없다. 하지만 static은 ㄱ나ㅡㅇ.

    void(*f3)(int) = &X::mf2;
    
    f1(10); // ok
   // f2(10);; //error

    X obj;
    X* pObj= &obj;
   // obj.f2(100); //error

    // pointer to member
    // obj.*f2(10); //error // 연산자 우선순위 문제
    (obj.*f2)(10); //error // 연산자 우선순위 문제
    (pObj->*f2)(10); //error // 연산자 우선순위 문제


}