/*
컴파일러 최적화에 대한 코드
특정 조건이 발생할 확률이 높ㅁ음을 알려줌.
*/

int foo(int i)
{
    if(i>0)[[likely]] // 해당 조건을 알려주면서 최적화를 더 좋게할 수 있음.
    {
        i+=2;
    }
    else
    {
        i-=2;
    }
    return i;
}

int main()
{
    foo(10);
    return 0;
}