#include <iostream>
template <int v> 
struct Int2Type 
{ 
 enum { value = v }; 
}; 
//  the value that generates the type is "saved" in the enum member value.
//  This way you can select different functions, depending on the result of a compile-time calculation. Effectively,
//  you achieve static dispatching on a constant integral value. 
int main()
{
    Int2Type<0> a;
    std::cout << a.value <<std::endl;
    return 0;
}

// 오버 로딩을 통한, if, eslse 구문 대체
// template <typename T, bool isPolymorphic> 
// class NiftyContainer 
// { 
// private: 
//  void DoSomething(T* pObj, Int2Type<true>) 
//  { 
//  T* pNewObj = pObj->Clone(); 
//  ... polymorphic algorithm ... 
//  } 
//  void DoSomething(T* pObj, Int2Type<false>) 
//  { 
//  T* pNewObj = new T(*pObj); 
//  ... nonpolymorphic algorithm ... 
//  } 
// public: 
//  void DoSomething(T* pObj) 
//  { 
//  DoSomething(pObj, Int2Type<isPolymorphic>()); 
//  } 
// }; 
// template <typename T, bool isPolymorphic> 
// class NiftyContainer 
// { 
//  ... 
//  void DoSomething() 
//  { 
//  T* pSomeObj = ...; 
//  if (isPolymorphic) 
//  { 
//  T* pNewObj = pSomeObj->Clone(); 
//  ... polymorphic algorithm ... 
//  } 
//  else 
//  { 
//  T* pNewObj = new T(*pSomeObj); 
//  ... nonpolymorphic algorithm ... 
//  } 
//  } 
// };