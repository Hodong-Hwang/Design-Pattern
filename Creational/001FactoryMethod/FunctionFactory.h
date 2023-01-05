#pragma once
#include <stdio.h>
#include <memory>
#include <map>
#include <string>
#include <functional>

using namespace std;

struct Drink
{
    virtual void prepare (int volume) = 0 ;
};

struct HotDrink : Drink
{
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override
    {
        printf("Take Tea bag, boil water, pour %iml, add some lemnon \n");
    }
};

struct Coffee : HotDrink
{
    void prepare(int volume) override
    {
        printf("Take espresso, boil water, pour %iml \n");
    }
};

enum class TeaType{
    Tea=0
    ,Coffee=1
};
std::unique_ptr<HotDrink> make_drink(TeaType type)
{
    std::unique_ptr<HotDrink>  drink;;
    switch (type){
        case (TeaType::Tea):{
            drink=std::make_unique<Tea>();
            drink->prepare(400); 
            break;
        }
        case (TeaType::Coffee):{
            drink=std::make_unique<Coffee>();
            drink->prepare(425); 
        }
    }
    return drink;
}

class DrinkFactory
{
    map<string,function<unique_ptr<HotDrink>()>> factories;
    public:
    DrinkFactory()
    {
        factories["coffee"]=make_unique<Coffee>;
        factories["Tea"]=make_unique<Tea>;
        // with prepare factories[]
    }
    unique_ptr<HotDrink> make_drink(std::string teatype)
    {
        auto ptr= factories[teatype]();
        ptr->prepare(200);
        return ptr;
    }

};