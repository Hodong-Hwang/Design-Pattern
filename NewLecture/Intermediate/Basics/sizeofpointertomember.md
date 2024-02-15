
다중 상속과 this에 대해서 이해하여함


```C++
struct A {int x;}
struct B {int y;}
struct C {int z;}
int main()
{
    C cc;
    &cc; // 1000;
    A* pA= &cc; //1000;
    B* pB= &cc; //1004; 
}
```

상속인 경우 메모리 주소를 생각해보자 다중 상속인 경우 주소가 달라짐.
B가 시작 되는 주소를 찾아서 받아줌.

reinterpret_cast<B*>(&cc)를 사용하는 경우 무조건 1000번지가 들어옴 -> 1000번지 메모리를 B처럼 쓰겠다는 거임.

만약 pB2->y=10; 을 하게 된다면 cc.x는 10으로 출력이 된다.




