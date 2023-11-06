#include <bitset>
#include <iostream>

int main()
{
    std::bitset<8> b1=0xf0;
    std::bitset<8> b2=0b1111000;

    std::cout << b1 <<std::endl;
    std::string s=b1.to_string();
    unsigned long un=b1.to_ulong();
    //biteset set, reset, []
    // 

    std::cout << s<< ", " <<un <<std::endl;
    b1.set(1);
    b1.flip(0);
    std::cout <<b1 <<std::endl;
    b1.none(); // a모든게 영
    int n2 = b1.count();// 1의 갯수
    b1.test(1);// == ㅠ1[1]=true 1번째가 1인지
    // 비트 연산가능
    auto b4 = b1 | b2;
    std::cout<< b4 <<std::endl;


}