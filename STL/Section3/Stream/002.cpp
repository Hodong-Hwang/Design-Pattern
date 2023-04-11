#include <iostream>
#include <iterator>
#include <list>
#include <fstream>
using namespace std;

int main ()
{
    ofstream f("a.txt");
    ostream_iterator<int>p (f,",");

    *p=20;
    *p=30;
}