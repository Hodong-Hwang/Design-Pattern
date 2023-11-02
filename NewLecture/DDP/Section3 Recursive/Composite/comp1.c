// Structural Pattern
//  복합객체를 트리구조로 만듦.
//  Composite Pattern을 클라이언트로 하려면 개별객체와 복합객체를 동일하게 다룰 수 잇도록한다.


#include <cstdio>

int main()
{
    printf("1. gimbab \n");
    printf("2. ramyeon \n");
    printf("3. End \n");

    int cmd = 0;
    scanf_s("%d",&cmd);

    switch (cmd)
    {
    case 1 :
        break;
    case 2 :
        break;
    case 3 :
        break;
    default:
        break;
    }

}
// 위 개념을 객체지향으로 변경