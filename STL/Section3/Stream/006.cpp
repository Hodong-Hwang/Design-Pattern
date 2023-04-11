#include <iostream>
#include <iterator>
#include <fstream>
using namespace std;

int main ()
{
    ifstream f("006.cpp");
    istreambuf_iterator<char> p1(f),pend;
    ostream_iterator<char> p2(cout);

    copy(p1,pend,p2);
}