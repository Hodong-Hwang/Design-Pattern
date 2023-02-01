
// 앞서 II부의 도입부에서 이야기했듯이 구성(composition) 관계와 연관(aggregation) 관계는 서로 동등한 것으로 취급한다.
#include <cmath>
#include <iostream>
#include <array>
#include <algorithm>
class Creature
{
    enum Abilities {
        str,agl,intl,count        
    };
    std::array<int, count> abilities;
public:

    // 다른 get/set 멤버 함수들...
    int get_strength() const { return abilities[str]; }
    void set_strength(int value) { abilities[str] = value; }
    int sum () const
    {
        return sum() / (double)count;   
    } 
    double average() const {
        return sum()/3.0;
    }
    int max() const {
        return *max_element(abilities.begin(), abilities.end());
    }
};