/*
    Abstract factory -> DDP
    Factory -> 관례적으로 사용함.
*/


#include <iostream>
#include <vector>
#include "../singleton.h"
#include <map>
class Shape{
    public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};
class Rect : public Shape
{
    public :
        void draw() override {std::cout << "draw Rect" <<std::endl;}
    static Shape* create() {return new Rect;}
};

class ShapeFactory
{
    MAKE_SINGLETON(ShapeFactory)

    using F = Shape* (*)();
    std::map<int,F> create_map;
public:
    void register_shape(int key, F create_function)
    {
        create_map[key] = create_function;
    }

    Shape* create(int type){
        Shape *p =nullptr;
        if(create_map[type] !=nullptr)
        {
            p=create_map[type]();
        }
        return p;
    }

};

int main()
{
    std::vector <Shape*> v;

    ShapeFactory& factory = ShapeFactory::getInstance();
    factory.register_shape(1,&Rect::create);
    while (1)
    {
        int cmd ;
        std::cin >> cmd;
        if(cmd >0 && cmd<8)
        {
            Shape* s =factory.create(cmd);
            if (s)
                v.push_back(s);
        }
    }

}