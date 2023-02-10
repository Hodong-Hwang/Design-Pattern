#include <iostream>
#include <typeinfo>
template <typename T> void foo(T a) 
{
    std::cout << typeid(T).name() <<std::endl;
}

template <typename T, typename U> 
struct pair
{
    T first;
    U second;
    pair(const T& a, const U& b) :first(a),second(b){}
};//pair


// bfore cpp17
template <typename T, typename U>
pair<T,U> make_pair(const T& a, const U& b)
{
    return pair<T,U>(a,b);
}

// Indentity

template <typename T> struct identity
{
    typedef T type;
};; // idnetity

template <typename T> void goo(T a) {}
//T
template <typename T> void bar(typename identity<T>::type a){}
//T << identity 를 이용하는 이유.. identity의 <T>를 결정해주어야함. 
int main ()
{
    pair<int,double> p (1,3.4);
    foo(p);
    foo(pair<int,double>(1,3.4));
    foo(make_pair(1,3.4));

    identity<int>::type n;
    foo(n);
    //
    //bar(3); // error 
    // identity type 해결을 위해서 -> 
}