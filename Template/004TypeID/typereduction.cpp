template <typename T> void foo(T a)
{
    ++a;
}


// 컴파일러가 Type을 결정하는 규칙 .
//

int main ()
{
    int n =0;
    int& r =n;
    const int c= n;
    const int& cr=c;

    foo(n); //int 
    foo(c); // int 
    foo(cr); // int
    foo(r); // int type// r has error ( because of T type is const T)
}