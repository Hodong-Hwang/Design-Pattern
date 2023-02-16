
//lvalue rvalue 모두 받도록 하는 것
// 1. 인자로 전달된 객체의 복사생성 (call by value)
//void foo(int arg){}

// 2. const lvalue reference
// 복사본은 생성되지 않지만, cosnt 속성을 가리킨다. 
// void foo(const int& arg){}

// 3. lvalue 버전과 rvalue 버전을 따로 제공하는 것

// void foo(int& arg){}
// void foo(int&& arg){}

// 4. foraridng reference
// Move Semantic // Perfect foarding에 응용.

// 주의사항.
template<typename T>
class Test
{
    public:
    void foo(T&& arg){}
    template<typename U> void goo(U&& arg){};
};
template <typename T> void foo(T&& arg){}
int main ()
{
    int n =0;
    foo(n);
    foo(0);

    Test<int> t; //해당 시점에서 int&& 에 해당하는 foo 함수가 생성됨.
    t.foo(0); // 
    // t.foo(n);
    t.goo(0);
    t.goo(n);
}