#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// find ,

bool f1 (int a){return a%3==0;}
bool f2 (int a, int k){return a%k==0;}

// f2를 바로 전달하려면 bind가 필요함.

class F
{
    int value;
    public :
    F(int v):value (v)
    {

    }
    bool operator()(int n) const{
        return n% value ==0;
    }
};

int main()
{
    std::vector <int> v(10);
    std::iota(v.begin(),v.end(),1);

    auto r1 = std::find(v.begin(),v.end(),3);
    auto r2 = std::find_if(v.begin(),v.end(),f1);
    // 정수하나의 배수를 입력 받는 것이 가능한기?

    int k ;
    std::cout << "Enter the integer to obtain the multiple. " << std::endl;
    std::cin >> k;
    auto r3 = std::find_if(v.begin(),v.end(),F(k));

    std::cout << *r3 <<std::endl;

}