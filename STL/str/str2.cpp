#include <iostream>
#include <string>
#include <complex>
using std::string;
using std::cout;
using std::endl;
void foo(string s) {cout <<"string"<<endl;}
void foo(const char* s) {cout << "char*" <<endl;}

int main ()
{
    using namespace std::literals;
    foo("hello"s); // user defines literals

    std::complex<double> c =3i;

    
}