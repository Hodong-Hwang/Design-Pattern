#include <iostream>
template<typename T> // MyAllocList<T>
using MyAllocList = std::list<T, MyAlloc<T>>; // is synonym for

typedef void (*FP)(int, const std::string&); // typedef
// same meaning as above
using FP = void (*)(int, const std::string&); // alias
 // declaration

// we need to bind in strcut
template<typename T> // MyAllocList<T>::type
struct MyAllocList { // is synonym for
 typedef std::list<T, MyAlloc<T>> type; // std::list<T,
}; 

// ypedef inside a template for the purpose of creating a linked list 
// holding objects of a type specified by a template parameter,typename MyAllocList<T>::type list; // as a data member
//  MyAllocList<T> list; // no "typename",no "::type
std::remove_const<T>::type // yields T from const T 
std::remove_const_t<T> 
std::remove_reference<T>::type // yields T from T& and T&&
std::remove_reference_t<T>
std::add_lvalue_reference<T>::type // yields T& from T
std::add_lvalue_reference_t<T>

template <class T>
using remove_const_t = typename remove_const<T>::type;
template <class T>
using remove_reference_t = typename remove_reference<T>::type;
template <class T>
using add_lvalue_reference_t =
 typename add_lvalue_reference<T>::type;