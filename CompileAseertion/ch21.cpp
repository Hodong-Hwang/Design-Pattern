template<bool> struct CompileTimeChecker 
{ 
 CompileTimeChecker(...); 
}; 
template<> struct CompileTimeChecker<false> { }; 
#define STATIC_CHECK(expr, msg) \
{\
class ERROR_##msg {};\
(void)sizeof(CompileTimeChecker<(expr) != 0>((ERROR_##msg())));\
} 

template <class To, class From> 
To safe_reinterpret_cast(From from) 
{ 
 STATIC_CHECK(sizeof(From) <= sizeof(To),Destination_Type_Too_Narrow); 
 return reinterpret_cast<To>(from); 
} 
void ex1()
{
    void* somePointer ; 
    char c = safe_reinterpret_cast<char>(somePointer); 

}
int main()
{
    ex1();
    return 0;
}