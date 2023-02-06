#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <typeinfo>
template <typename T>
class ElementT; // primary template

template <typename T>
class ElementT<std::vector<T> > { // partial specialization
public:
typedef T Type;
};
template <typename T>
class ElementT<std::list<T> > { // partial specialization
public:
typedef T Type;
};
template <typename T>
class ElementT<std::stack<T> > { // partial specialization
public:
typedef T Type;
};
template <typename T>
void print_element_type (T const & c)
{
std::cout << "Container of "
<< typeid(typename ElementT<T>::Type).name()
<< " elements.\n";
}

template <typename C>
class ElementT {
    public:
typedef typename C::value_type Type;
};