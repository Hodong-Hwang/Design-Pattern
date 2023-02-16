
#include <iostream>
#include <vector>
#include <algorithm>
bool f1 (int a) {return a%3==0;}

// int 사용자가 입력한 변수를 가지고 있어야함.
// 이런 것을 가능하도록 하는 것이 closure임
//bool f2 (int a) {return a%3==0;}

int main ()
{
    std::vector<int> v= {1,2,3,4,5,6,7,8,9};

    auto r1 = std::find(v.begin(),v.end(),3);
    auto r2 = std::find_if(v.begin(),v.end(),f1);
    // 조건자는 불로 변환 가능하는 함수객체

    int k ;
    std::cin >> k;

    auto r3=std::find_if(v.begin(),v.end(),f1);

}
