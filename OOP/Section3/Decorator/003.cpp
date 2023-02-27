#include <iostream>

using namespace std;
struct Component
{
    virtual void Fire() = 0;
    virtual ~Component() {}
};
class SpaceCraft : public Component
{
    int color;
    int speed;
    public : 
    void Fire() {cout << "Space Craft : --------------" <<endl;}
};



class LeftMissile : public Component
{
    Component* craft;
    public:
    LeftMissile (Component * p ) : craft(p) {}
    void Fire()
    {
        craft->Fire();
        cout << "Left Missile : >>>>>>>>>>>" <<endl;
    }
};
class RightMissile  : public Component
{
    Component* craft;
    public:
    RightMissile (Component * p ) : craft(p) {}
    void Fire()
    {
        craft->Fire();
        cout << "Right Missile : >>>>>>>>>>>" <<endl;
    }
};
int main ()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm(&sc);
    lm.Fire();

    // LeftMissile rm(&sc); // new object... 
    RightMissile rm(&lm);
    rm.Fire();
    return 0;
}