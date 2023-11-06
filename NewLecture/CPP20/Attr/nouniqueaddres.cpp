#include <iostream>

// struct Empty
// {

//     // 가상함수는 가상함수 데테이블이 잡힘.
//     virtual void foo();
// };

struct Empty
{
    // 가상함수가 없고, static이 없어야함.
    void foo();
};

struct Data
{
    Empty e;
    int n; // 4byte padding이 좋음.
};

struct Data2
{
    [[no_unique_address]]Empty e; //byte가 안잡혀서 총 4byte로 만족할 ㅜㅅ 있음.
    int n; // 4byte padding이 좋음.
};
int main()
{
    //empty class는 1bvyte
    std::cout << sizeof(Empty)<< std::endl;
    // 8byte
    std::cout << sizeof(Data)<< std::endl;
    std::cout << sizeof(Data2)<< std::endl;


}
