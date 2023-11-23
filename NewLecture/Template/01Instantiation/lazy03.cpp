template <typename T> void foo(T n, int)
{
    *n = 3.4;
}

template <typename T> void foo(T n, double)
{
}
//어떤함수를 쓸건지는 컴파일시간에 결정됨.

int main()
{
    // no error
    // integral constant사용시 해당 기법을 이용함.
    foo(1,3.4);
}