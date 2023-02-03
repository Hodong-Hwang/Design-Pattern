#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;
struct Creature
{
    string name;
    int attack, defense;
    Creature(const string &name, const int attack, const int defense)
        : name(name),
          attack(attack),
          defense(defense)
    {
    }

    friend ostream &operator<<(ostream &os, const Creature &obj)
    {
        return os
               << "name: " << obj.name
               << " attack: " << obj.attack
               << " defense: " << obj.defense 
               << "\n";
    }
    friend ostream &operator<<(ostream &os, const std::vector<Creature> &objs)
    {
        for (const auto& obj : objs)
        {
            os << obj;
        }
        return os;
    }
};

class CreatureModifier
{
    CreatureModifier *next{nullptr};

protected:
    Creature &creature; // 참조 대신 포인터나 shared_ptr를 사용할수도 있다.
public:
    explicit CreatureModifier(Creature &creature)
        : creature(creature) {}


    void add(CreatureModifier *cm)
    {
        if (next)
            next->add(cm);
        else
            next = cm;
    }

    virtual void handle()
    {
        if (next)
            next->handle(); // 핵심적인 부분!
    }
};

class DoubleAttackModifier : public CreatureModifier
{
public:
    explicit DoubleAttackModifier(Creature &creature)
        : CreatureModifier(creature) {}

    void handle() override
    {
        cout <<" DoubleAttackModifier" << endl;

        creature.attack *= 2;
        CreatureModifier::handle();
    }
};

class IncreaseDefenseModifier : public CreatureModifier
{
public:
    explicit IncreaseDefenseModifier(Creature &creature)
        : CreatureModifier(creature) {}

    void handle() override
    {   
        cout <<" IncreaseDefenseModifier" << endl;
        if (creature.attack <= 2)
            creature.defense += 1;
        CreatureModifier::handle();
    }
};

int main()
{
    Creature goblin{"Goblin", 1, 1};
    CreatureModifier root{goblin};
    DoubleAttackModifier r1{goblin};
    DoubleAttackModifier r1_2{goblin};
    IncreaseDefenseModifier r2{goblin};

    std::vector <Creature> Creatures;
    root.add(&r1);
    root.add(&r1_2);
    root.add(&r2);

    root.handle();
    Creatures.emplace_back(goblin);
    Creatures.push_back({"Goblin2", 1, 1});
    cout << Creatures ;
    // 출력 결과 "name: Goblin attack: 4 defense: 1"
}