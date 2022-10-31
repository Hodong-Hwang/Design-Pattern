class WidgetB
{
public:
    WidgetB(){};
};
class WidgetA
{
public:
    WidgetA(){};
    WidgetA(WidgetB arg_){arg=arg_;};
    WidgetB arg;
};
template <class T, class U> 
T* Create(const U& arg) 
{ 
 return new T(arg); 
}

// const U& arg -> Overlaoding이 필요함.
template <class T, class U> 
T* Create(const U& arg, T /* dummy */) 
{ 
 return new T(arg); 
} 
template <class U> 
WidgetA* Create(const U& arg, WidgetA /* dummy */) 
{ 
 return new WidgetA(arg); 
} 
// template <class U> 
// WidgetA* Create<WidgetA, U>(const U& arg) 
// { 
//  return new Widget(arg); 
// } 
template <typename T> 
struct Type2Type 
{ 
 typedef T OriginalType; 
}; 
template <class T, class U> 
T* Create1(const U& arg, Type2Type<T>) 
{ 
 return new T(arg); 
} 
template <class U> 
WidgetA* Create1(const U& arg, Type2Type<WidgetA>) 
{ 
 return new WidgetA(arg); 
} 
void ex1()
{
    WidgetB arg;
    WidgetA* a =Create<WidgetA,WidgetB>(arg); 
}
//The second parameter of Create serves only to select the appropriate overload. Now you can specialize 
// Create for various instantiations of Type2Type, which you map to various types in your application. 

void ex2()
{
    WidgetB arg;
    WidgetA* a =Create1(arg,Type2Type<WidgetA>()); 
}
int main()
{
    return 0;


}