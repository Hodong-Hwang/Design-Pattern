#include "../OOP/Section6/singleton.hpp"
#include <iostream>
#include <map>
class Shape
{
    public: 
        virtual void Draw() {std::cout <<"Draw Sahpe" <<std::endl;}
};

class ShapeFactory
{
    MAKE_SINGLETON(ShapeFactory)
    typedef Shape* (*CREATOR)();
    std::map<int,CREATOR> create_map;
    public:
    void Register(int type, CREATOR f)
    {
        create_map[type]=f;
    }
    Shape* CreateSahpe(int type)
    {
        Shape* p=0;
        auto ret =create_map.find(type);
        if(ret!=create_map.end()) return 0;

        p=create_map[type]();
        return p;
    }

};

struct RegisterShape
{
    RegisterShape(int type, Shape* (*f)())
    {
        ShapeFactory& factory =ShapeFactory::getInstance();
        factory.Register(type,f);
    }
};
#define DECLARE_SHAPE(classname) \
static* Shape Create() {return new classname;} \
static RegisterShape rs; \

#define IMPLEMENT_SHAPE(type,classname) \
    RegisterShape classname::rs(type,&classname::Create) \

class Rect : public Shape
{
    public: 
        virtual void Draw() {std::cout <<"Draw Rect" <<std::endl;}
        static Shape* Creaate() {return new Rect;}
    DECLARE_SHAPE(Rect)
};
IMPLEMENT_SHAPE(2,Rect)


class Circle : public Shape
{
    public: 
        virtual void Draw() {std::cout <<"Draw Circle" <<std::endl;}
};



int main ()
{
    
    return 0;
}