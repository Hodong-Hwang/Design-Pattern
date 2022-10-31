// std::type_info
// which gives you the ability to investigate object types at runtime
//  type_info in conjunction with the typeid operator
// a reference to a type_info

// typeid operator returns a reference to an object of type type_info. 
// operator== and operator!=, type_info provides two more functions
#include <typeinfo>
#include <iostream>
#include "../../cpg_types.hpp"
void Fun(int pObj,int a) 
{ 
    int b=1;
    if (typeid(pObj) == typeid(b)) 
    {
        std::cout <<  "pObj actually points to a Derived object" <<std::endl;
        std::cout << Cpg_GetTypeCategory(pObj) <<std::endl;
    } 
} 
class TypeInfo 
{ 
public: 
    // Constructors/destructors 
    TypeInfo(); // needed for containers 
    TypeInfo(const std::type_info&); 
    TypeInfo(const TypeInfo&); 
    TypeInfo& operator=(const TypeInfo&); 
    // Compatibility functions 
    bool before(const TypeInfo&) const; 
    const char* name() const; 
    private: 
    const std::type_info* pInfo_; 
}; 
// Comparison operators 
    bool operator==(const TypeInfo&, const TypeInfo&); 
    bool operator!=(const TypeInfo&, const TypeInfo&); 
    bool operator<(const TypeInfo&, const TypeInfo&); 
    bool operator<=(const TypeInfo&, const TypeInfo&); 
    bool operator>(const TypeInfo&, const TypeInfo&); 
    bool operator>=(const TypeInfo&, const TypeInfo&);
void ex1()
{
    int a =1;
    Fun(a,a);
}
int main()
{
    ex1();
    return 0;
}
// typeid operator returns a reference to an object of type type_info.
// const char*. There is no standardized way of mapping class names to strings,
// so you shouldn't expect typeid(Widget) to return "Widget"