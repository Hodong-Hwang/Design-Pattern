
int add1(int a, int b)
{
    return a+b;
}

inline int add2(int a, int b)
{
    return a+b;
}

int main ()
{
    int ret1 = add1(1,2);
    int ret2 = add2(1,2);

    int(*f)(int,int)= &add2;

    f(1,2); // 호출됨. 컴파일 시간에 결정 안됨.
}