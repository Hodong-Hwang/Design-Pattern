#include <iostream>
#include <complex>

using namespace std;

int main ()
{
    complex<double> c1(1,0);

    cout << c1<<endl;

    complex<double> c2 =sin (c1);

    cout <<c2 <<endl;
}