#include <iostream>
#include <iterator>
#include <list>

using namespace std;


int main ()
{
    int n =10;
    cout << n <<endl;

    ostream_iterator<int>p (cout, ",");
    *p=200;
    *p=10;
    list <int> s ={1,2,3};
    fill_n(begin(s),3,0);
    copy(begin(s),end(s),p);
    fill_n(p,3,0);

}