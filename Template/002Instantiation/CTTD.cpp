#include <iostream>
#include <stdlib.h>
#include <list>
#include <typeinfo>

template <typename T>
class Vector
{
    T *buff;
    public:
    Vector(){
        buff=nullptr;
    }
    Vector(int sz, T initValue ){

        buff =(T*)malloc(sz*sizeof(T));
        for (int i= 0; i<sz; i++)
        {
            buff[i] = initValue;
        }
    }

    template <typename C> Vector(C& c) {};
    ~Vector ()
    {
        free(buff);
        buff =nullptr;
    }
    size_t size() {
        return _msize(buff)/sizeof(T);
    }
    friend std::ostream& operator << (std::ostream& os, Vector<T> vec)
    {
        for (int i = 0; i<vec.size(); i++)  os <<vec.buff[i] << ",";
        return os;
    }

};

// User Define Deduction Guide

// vector v3
Vector() -> Vector<int>; //depreacated method .
template <typename C> 
//Vector(C& c)->Vector<C>; // list<int>
Vector(C& c)->Vector<typename C::value_type>; // int


int main ()
{
    Vector <int> v1(10,3); // 3,3,3,3,,3,3 ...
    std::cout <<v1 <<std::endl;
    std::cout <<"after c++ 17" <<std::endl;
    // Vector  v2(10,3); // c++17
    // std::cout <<v2<<std::endl;
//    Vector v3;
   // std::list s ={1,2,3};
    // std::cout << "type id of s =" << typeid(s).name()<<std::endl;
    // std::cout << "type id of s =" << typeid(typename std::list<int>::value_type).name()<<std::endl;

    return 0;

}