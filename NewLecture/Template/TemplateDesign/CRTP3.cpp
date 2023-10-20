#include <iostream>

template <typename T>
class Object
{
public:
    static int cnt;
    Object () {++cnt;}
    ~Object() {--cnt;}
    static int getCount() {return cnt;}
};

template <typename T> int Object<T>::cnt = 0;

class Mouse : public Object <Mouse>
{

};
class Keybodard : public Object <Keybodard>
{

};

int main ()
{
    Mouse m1,m2;
    Keybodard k1,k2;

    std::cout << k1.getCount() <<std::endl;
}