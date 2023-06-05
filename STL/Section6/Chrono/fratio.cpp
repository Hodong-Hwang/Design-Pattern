
#include <iostream>
#include <ratio>

using namespace std;

void ex1()
{
    ratio_add<ratio<1,4>,ratio<2,4>>r2 ; 
    cout << r2.num <<endl;
    cout << r2.den <<endl;
    ratio <1,1000> millim;
    milli m ;
    kilo k;

    cout << k.num <<endl;
    cout << k.den <<endl;
}
int main ()
{
    ratio<2,4> r1; 

    cout << r1.num <<endl;
    cout << r1.den <<endl;
    cout << sizeof(r1) <<endl; /// Compile memory.
    cout << ratio<2,4>::num <<endl;
    ex1();
}