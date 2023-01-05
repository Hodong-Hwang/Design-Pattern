#pragma once
#include <stdio.h>
#include <memory>
#include <map>
#include <string>
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

struct HotDrinkFactory
{
    virtual std::unique_ptr<HotDrink> make() const =0;
};
struct CoffeeFactory : HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() const override
    {
       return std::make_unique<Coffee>();
    }

};

struct TeaFactory : HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() const override
    {
       return std::make_unique<Tea>();
    }

};
class DrinkFactory
{
    map<string,unique_ptr<HotDrinkFactory>> hotdrink_factories;
    public:
    DrinkFactory()
    {
        hotdrink_factories["coffee"]=make_unique<CoffeeFactory>();
        hotdrink_factories["Tea"]=make_unique<TeaFactory>();

    }
    unique_ptr<HotDrink> make_drink(const string& name)
    {
        auto drink = hotdrink_factories[name]->make();
        drink->prepare(200);
        return drink;
    }
    
};