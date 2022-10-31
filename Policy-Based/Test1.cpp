
// class Widget;
// template <class T, class U> class SmartPtr{};

// template <class U> class SmartPtr<Widget, U> {};
// template <class T> class Widget
// {
//     void Fun(){};
// };
// template<> void Widget<char>::Fun()
// {
//     return ;    
// }
// template<> void Widget<int>::Fun()
// {
//     std::cout << "int Type" <<std::endl;
//     return ;    
// }

#include<iostream>
#include <string>
template<class T>
struct OpNewCreator
{
    static T* Create()
    {
        return new T;
    }
protected : 
    ~OpNewCreator(){};
};
template <class T>
struct MallocCreator
{
    static T* Create()
    {
        void *buf = std::malloc(sizeof(T));
        if(!buf) return 0;
        return new(buf) T;
    }

};
template <class T>
struct PrototypeCreator
{
    PrototypeCreator(T* pObj =nullptr) : pPrototpye_(pObj){};
    T* Create()
    {
        return pPrototpye_ ? pPrototpye_->Clone() : nullptr;
    }
    T* GetPrototype() {return pPrototpye_;}
    void SetPrototype(T* pObj) { pPrototpye_ = pObj; } 
    
private: 
    T* pPrototpye_;
};
class Widget{
public:
    Widget(){};
    std::string classname = "Widget";

};
// This all means that WidgetManager can benefit from optional enriched interfaces but still work correctly 
// with poorer interfaces—as long as you don't try to use certain member functions of WidgetManager. 
template <template<class> class CreationPolicy> 
class WidgetManager : public CreationPolicy<Widget>
{ 
//  ...
    WidgetManager()= default;
public:
    void SwtichProtoTpye(Widget* pNewPrototype) 
    {
        CreationPolicy<Widget>& myPolicy =*this;
        delete myPolicy.GetPrototpye();
        myPolicy.SetPrototype(pNewPrototype)

    }
}; 
// template <template <class Created> class CreationPolicy>
// class WidgetMansger2: public CreationPolicy<Widget>
// {

// };

int main ()
{
    typedef WidgetManager< OpNewCreator<Widget> > MyWidgetMgr; 
    MyWidgetMgr mgr;
    auto widget = mgr.Create();
    std::cout << widget->classname << std::endl;
    
   return 0;
}