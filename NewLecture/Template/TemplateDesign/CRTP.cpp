#include <iostream>
template <typename T>
class Base 
{
    public :
    Base()
    {
        std::cout <<typeid(T).name()  <<std::endl;
        static_cast<T*> (this)->OnClick();
    }
    void OnClick()
    {
        std::cout <<"On Click" <<std::endl;
    }

};

// Cast 위주로 사용함.
class Derived : public Base<Derived>{

    public:
    void OnClick()
    {
        std::cout <<"On Click (Derived)" <<std::endl;
    }
};


int main()
{
    Derived a;

}