int add1(int a, int b)
{
    return a+b;
}

inline int add2(int a, int b)
{
    return a+b;
}


int main()
{
    int ret2 = add2(1,2);
    int (*f)(int,int) = &add2;

    // inline함수가 변수로 될 지??

    f(1,2); // 호출만 됨. 치환되지 않음.
    // 함수 포인터에 담으면 치환되지 않는다. 
}