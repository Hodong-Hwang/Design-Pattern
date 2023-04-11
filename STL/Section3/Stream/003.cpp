#include <iostream>
#include <iterator>

using namespace std;


int main ()
{

    ostreambuf_iterator<char>p (cout);
    *p=10;
    *p=65;
    streambuf* ubf =cout.rdbuf();
    ubf->sputc(65);
    //fill_n(p,3,0);

}