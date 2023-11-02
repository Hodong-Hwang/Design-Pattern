#include <iostream>

struct Base
{
    int value = 10;
    Base() =default;
    Base (const Base& b) : value (b.value)
    {
        std::cout << "Base Copy" << std::endl;
    }
};

struct Derived : public Base
{
    int value = 20;
};


void ex1()
{
    Derived d;
    // 여기서는 20
    std::cout << d.value <<std::endl;
    std::cout << static_cast<Base&>(d).value <<std::endl; // 10;
    // 아래으 ㅣ경우 base Temporary type이 만들어져서 반환이 된다.
    std::cout << static_cast<Base>(d).value <<std::endl; // 10; // 위와 아래의 차이.
    
    static_cast<Base>(d).value=15; // error
    static_cast<Base&>(d).value=15; // ok

}

int main()
{
    ex1();
}