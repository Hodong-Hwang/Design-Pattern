#include <list>
using namespace std;

template <typename T> class Vector
{
    T* buff;
    int size;
    public :
    Vector (int sz, T value){}


    template <typename C>
    Vector(C c){}


};

template <typename C>
Vector(C c)->Vector<typename C::value_type>;
// template <typename C>
// Vector(C c)->Vector<typename C::Iterator>;

int main()
{
    Vector v(10,3);
    list s={1,2,3};
    Vector V2(s);
    Vector v3(s.begin());
}