#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main ()
{
    bitset<8> b1; // 0;
    b1.set(); // 1111 1111

    b1.set(1); // 0000 0010
    b1[2]=1; /// 0000 0110
    b1[0].flip(); // 0000 0111

    bitset<8> b2= 0xf0; //1111 0000

    if(b1.test(1)==true) {}

    if(b1.none()==true){}
    int n2 =b1.count();
    cout <<n2 << endl;
    std::cout << b1 <<endl;
    std::cout << b2 <<endl;

    string s2 = b1.to_string();
    string s3 = b2.to_string();

    unsigned long n =b1. to_ulong();

    std::cout <<s2 <<std::endl;
    std::cout <<s3 <<std::endl;
    std::cout << n << std::endl;
    return 0;

}