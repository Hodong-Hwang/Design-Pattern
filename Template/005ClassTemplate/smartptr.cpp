#include <memory>

using namespace std;
class Animal {};
class Dog: public Animal{};

int main()
{
    shared_ptr <Dog> p1 (new Dog);
    shared_ptr <Animal> p2=p1;
    p2=p1;
    if(p1==p2){}
    if(p2!=p1){}
}