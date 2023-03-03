#include <iostream>
#include <vector>

using namespace std;


int main ()
{
    vector <int > v {1,2,3,4,5};

    auto p =begin(v);

    v.resize(100);

    cout << *p <<endl;

    return 0;
}