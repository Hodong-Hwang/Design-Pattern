#include <set>
#include <string>
#include <iostream>
struct People
{
    People(int id, std::string name_) : id(id),name(name_){}
    People(int id, const char* name_) : id(id),name(name_){}

    int id;
    std::string name;
};

struct PeopleComapre
{
    bool operator()(const People& p1, const People& p2) const{
        return p1.id<p2.id;
    }
    bool operator()(const People& p1, int id) const{
        return p1.id<id;
    }
    bool operator()(int id, const People& p2) const{
        return id<p2.id;
    }
    using is_transparent = int;
};


int main()
{
    std::set <People,PeopleComapre> s;

    s.emplace(1,"lee");
    s.emplace(2,"kimm");

    People p{1,"lee"};
    auto ret =s.find(p);
    std::cout <<ret->name <<"," << ret->id << std::endl;
   auto ret2=s.find(1);
   std::cout <<ret2->name <<"," << ret2->id << std::endl;

    // id만 가지고 find할 수 있지 않을까?
}