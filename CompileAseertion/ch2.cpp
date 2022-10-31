// • Compile-time assertions 
// • Partial template specialization 
// • Local classes 
// • Mappings between types and values (the Int2Type and Type2Type class templates) 
// • The Select class template, a tool that chooses a type at compile time based on a Boolean condition 
// • Detecting convertibility and inheritance at compile time 
// • TypeInfo, a handy wrapper around std::type_info
// • Traits, a collection of traits that apply to any C++ type

// safte casting lager types must not cast to smaller types
#include <assert.h>
#include <iostream>
#include "../cpg_types.hpp"
// template <class To, class From>
// To  safe_reinterpret_cast (From from)
// {
//     assert(sizeof(From)<= sizeof(To)); // false -> error
//     return reinterpret_cast<To>(from); // reinterpret_cast , you can never be sure
// }
// void ex1()
// {
//     int i= 1; // Double -> error
//     char *p =safe_reinterpret_cast<char*>(i);
//     std::cout<<Cpg_GetTypeCategory(p)<<std::endl;
// }
// The idea is to pass the compiler a language construct that is legal for a nonzero expression 
// and illegal for an expression that evaluates to zero.
// This way, if you pass an expression that evaluates to zero, 
// the compiler will signal a compile-time error.  if on your system pointers are larger than characters, the compiler complains that you are trying to create an array of length zero. 
// #define STATIC_CHECK(expr) { char unnamed[(expr) ? 1 : 0]; }
// template <class To, class From> 
// To safe_reinterpret_cast(From from) 
// { 
//  STATIC_CHECK(sizeof(From) <= sizeof(To)); 
//  return reinterpret_cast<To>(from); 
// } 
// void ex1()
// {
//     double somepoint; // Double -> error
//     char c=safe_reinterpret_cast<char>(c);
//     std::cout<<Cpg_GetTypeCategory(c)<<std::endl;
// }

template<bool> struct CompileTimeError; 
template<> struct CompileTimeError<true> {}; 
template<> struct CompileTimeError<false> {};

#define STATIC_CHECK(expr) (CompileTimeError<(expr) != 0>()) 
template <class To, class From> 
To safe_reinterpret_cast(From from) 
{ 
 STATIC_CHECK(sizeof(From) <= sizeof(To)); 
 return reinterpret_cast<To>(from); 
} 
void ex1()
{
    double somepoint; // Double -> error
    char c=safe_reinterpret_cast<char>(c);
    std::cout<<Cpg_GetTypeCategory(c)<<std::endl;
}
int main()
{
    ex1();
    return 0;
}