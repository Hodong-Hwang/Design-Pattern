#include <list>
#include <iostream>

template <typename ITER> class Reverse_Iterator
{
    ITER iter;
    public:
    Reverse_Iterator(ITER i) {iter =i ; --iter;}

    Reverse_Iterator& operator++()
    {
        --iter;
        return *this;
    }

    typename ITER::value_type operator*()
    {
        return *iter;
    }
};

int main ()
{
    std::list<int> s{1,2,3,4,5,6,7,8,9,10};
    auto p1=std::end(s);
    Reverse_Iterator<std::list<int>::iterator> p2(p1);

    ++p2;
    std::cout << *p2 << std::endl;
    return 0;
}