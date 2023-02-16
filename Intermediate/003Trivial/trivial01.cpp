

//special member function 
// 컴파일러가 제공하는 멤버함수
// default construct , destructor ,copy constructor , copy assigment
// move constructor
// move assignment -> Trivial하다 라고 정의함.

// 조건은 아무것도 하지않음 (생서자 소멸자)

#include <iostream>
#include <type_traits>


struct TrivialDefaultCtor
{
    int data;
};
struct NonTrivialDefaultCtor
{
    int data;
    NonTrivialDefaultCtor(){}

};

struct Type1
{
    Type1(int a){}
};

struct Type2
{   
    Type2(){}
    Type2(int a){}
};
struct Type3
{   
    Type3()=default;
    Type3(int a){}
};
template <class T> void check()
{
    std::out 
}