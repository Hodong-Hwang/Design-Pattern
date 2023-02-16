
template <typename T> void f4(T&& arg){}

int main ()
{
    int n=0;
    f4<int>(0); // T = int  T&& int&& f4(int&& arg)
    f4<int&>(n); // T = int  T&& int&& f4(int&& arg)
    f4<int&&>(0); // T = int&&  T&& int&& f4(int&& arg)
    

    // T&& -> universal reference = fowarding reference (모든 것을 받아드린다. -)
    f4(n); //T =int f4(int& arg) X -> T =int& f4(int& arg)
    f4(0); //T = int

    // 모두 잘 전달 될 수 있다.!
    // lvalue를 바등ㄹ 수 있는 함수가 생성되고, rvalue를 함수가 생성되는 것
    // f4(n) 생성타입이 매우 중요함.

}