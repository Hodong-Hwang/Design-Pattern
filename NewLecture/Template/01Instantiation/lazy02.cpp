template <typename T> void foo(T n)
{
    *n =10;
}

int main()
{
    // 아래 경우 실행시간에 진행됨
    if (false)
        foo(0);
    // Compiler가 실행시간에 조사함.. -> 일단 실행이 가능함.
    // 사용된다는 가정임.-> 그래서 컴파일 오류가 발생함.
    if constexpr (false) // compile 시간에 조사함.
        foo(0); //c++ 17에서 모두 사용가능함.
    // if constexpr은 static compiler라고함.
    // template에서 매우 핵심적인 기술임.
}