#include <iostream>

class URandom
{
    // member data cna be used.. 
    // 상태라는 것은 멤버 데이터를 의미함.
    // 동장 죽 멤버 데이터를 보관할 수 있다는 장점이 존재함.
public:
    int operator()()
    {
        return rand() % 10;
    }
};

URandom urand;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << urand() << ",";
    }
    std::cout << std::endl;
}