#include <iostream>
#include <cstring>


class Person
{
    char* name;
    int age;
    public:
    Person (const char* s, int a):age(a)
    {
        name =new char[strlen(s)+1];
        strcpy_s(name,strlen(s)+1,s);
    }
    ~Person(){delete[] name;}
    Person(const Person& p): age(p.age) // lavalue와 rvalue 모두 받을 수 있음.
    {
        std::cout <<"copy ctor" <<std::endl;
        name =new char[strlen(p.name)+1];
        strcpy_s(name,strlen(p.name)+1,p.name);
    }
    // 임시객체만 받을 수 있는 것
    Person (Person&& p): age(p.age) ,name(p.name)
    {
        // move 생성자. 얕은 복사가 이루어지니깐 굳이 move를 안해도됨.
        std::cout <<"move ctor" <<std::endl;
        p.name =nullptr;
    }
};

Person foo()
{
    Person p("jonhn",20);
    return p;
}

int main ()
{
    Person p1("John",20);
    //Person p2 = p1; //? 얕은 복사가됨.
    // 깊은 복사를 만들어야함.
    Person ret = foo(); // 임시 객체가 파괴가되면서 새로운 주소가 생성됨.

    //해당 문제를 해결하기 위해서 임시 객체를 위한 생성자를 만들어 주면됨.

}