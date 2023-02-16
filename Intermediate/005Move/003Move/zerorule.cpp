#include <iostream>
#include <type_traits>
class String
{
    public:
    String () = default;
    String (const String& obj) {std::cout << "String copy ctor" <<std::endl;}
    String (String&& obj) {std::cout << "String move ctor" <<std::endl;}
    String& operator =(const String&) {std::cout << "String Copy Assignemnt" <<std::endl; return *this;}
    String& operator =(String&&) {std::cout << "String move Assignemnt" <<std::endl; return *this;}

};

class Object
{
    String name;
    public:
    Object() = default ;
    Object (const Object& obj) : name(obj.name) { std::cout << "copy ctor" <<std::endl;}
    // Object(Object&& obj) {std::cout << "move ctor" <<std::endl;}
    // Object& operator = (const Object& obj) { name = obj.name; return *this;}
    // Object& operator = (Object&& obj) { name = std::move(obj.name); return *this;}

};

int main ()
{
    Object obj1;
    Object obj2=obj1;

    obj2 = obj2;
    Object obj3 = std::move(obj1);
    obj3 =std::move(obj1);

}