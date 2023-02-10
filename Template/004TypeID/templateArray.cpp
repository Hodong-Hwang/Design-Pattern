#include <iostream>
#include <boost/type_index.hpp>

using namespace std;
using namespace boost::typeindex;
template <typename T>
void foo(T a)
// T : int[3] error -> void foo(int* a)
{
    cout << type_id_with_cvr<T>().pretty_name() << endl;
    cout << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}

template <typename T>
void goo(T &a)
{
    cout << type_id_with_cvr<T>().pretty_name() << endl;
    cout << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}
// void goo( int (&a)[3]) is ok!
int main()
{
    int x[3] = {1, 2, 3};
    goo(x); //
    foo(x);
    // int y[3] =x ; //error
    // int *p =x;
    // int(&r)[3]=x;
}