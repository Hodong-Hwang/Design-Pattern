
#include <iostream>
#include <vector>
#include <algorithm>
class F
{
    int value;
    public:
    F(int v): value (v) {}
    bool operator () (int n) const{
        return n%3==0;
    }
};

int main ()
{
    std::vector<int> v= {1,2,3,4,5,6,7,8,9};

    auto r1 = std::find(v.begin(),v.end(),3);

    // 조건자는 불로 변환 가능하는 함수객체

    int k ;
    std::cin >> k;
    F f(k);
    auto r2 = std::find_if(v.begin(),v.end(),f);
    auto r3 = std::find_if(v.begin(),v.end(),F(k));

    std::cout << *r2 << std::endl;
    std::cout << *r3 << std::endl;

}
