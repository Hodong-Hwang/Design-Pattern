#include <iostream>
// ex01에서 중복되지 않는 난수를 구하려면 어떻게 해야할까?
// 실행 결과를 데이터를 보관해야한다. >> static, global ... 이렇게 하는 경우 무언가 단점들이 존재함.
// global = 코드 관리 문제, 
class URandom
{
    // member data
    // 동작 + 상태를 가지는 것 >> 즉 멤버를 가지는 것임.
    public:
        int operator() ()
        {
            return rand() % 10;
        }
};
URandom urand;
void ex01()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout <<urand() << "," ;
    }
    std::cout << std::endl;
}


int main()
{
    ex01();
}

