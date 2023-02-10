#include <iostream>
#include <boost/type_index.hpp>

using namespace std;
using namespace boost::typeindex;

template <typename T> void foo(const T a)
{
    // const volaitile reference
    cout <<type_id_with_cvr<T>().pretty_name() <<endl;
    cout <<type_id_with_cvr<decltype(a)>().pretty_name() <<endl;
}

int main ()
{
    int n=0;
    int& r = n;
    const int c= n;
    const int& cr = c;

    foo(n);
    foo(r);
    foo(c);
    foo(cr);
}

