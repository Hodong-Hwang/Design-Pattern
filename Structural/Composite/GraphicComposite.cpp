#include <iostream>
#include <string>
#include <vector>
struct  GraphicObject
{
    virtual void draw()=0;
};

struct Circle : GraphicObject
{
    void draw() override
    {
        std::cout << "Circle" << std::endl;
    }

};

struct Group : GraphicObject
{
    std::string name;
    explicit Group(const std::string& name):name{name}{}
    void draw() override
    {
        std::cout <<"Group" << name.c_str() << " Contains: " <<std::endl;
        for (auto&& o: objects)
        {
            o->draw();
        }
    }
    std::vector<GraphicObject*> objects; 
};

int main ()
{
    Group root("root");
    Circle c1,c2;
    root.objects.push_back(&c1);
    Group subgroup("sub");
    subgroup.objects.push_back(&c2);
    root.objects.push_back(&subgroup);
    root.draw();
}