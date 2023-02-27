#include <iostream>

using namespace std;

class SpaceCraft
{
    int color;
    int speed;
    public : 
    void Fire() {cout << "Space Craft : --------------" <<endl;}
};


class LeftMissile 
{
    SpaceCraft* craft;
    public:
    LeftMissile (SpaceCraft * p ) : craft(p) {}
    void Fire()
    {
        craft->Fire();
        cout << "Left Missile : >>>>>>>>>>>" <<endl;
    }
};
// 실행시간에 기능이 추가하는 것을 데코레이터 패턴이라고함.


int main ()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm(&sc); // new object... 
    lm.Fire();

    return 0;
}