#include <vector>
#include <iostream>

struct X
{
    X() {std::cout << "X() get resource" << std::endl;}
    ~X() {std::cout << "~X() release resource" << std::endl;}

};

int main()
{
    std::vector<X> v(10);
    v.resize(7);
    std::cout <<v.size() << std::endl; // 7
    // 메모리는 제거하지 않지만 소멸자만 호출
    std::cout <<v.capacity() << std::endl; // 10
    v.resize(8);

    std::cout <<v.size() << std::endl; // 8
    std::cout <<v.capacity() << std::endl; // 10

}