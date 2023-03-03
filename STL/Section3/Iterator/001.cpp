#include <iostream>
#include <list>

using namespace std;

int main ()
{
    int x[5]={1,2,3,4,5};

    int *p =x;

    list<int> s= {1,2,3,4,5};

    auto p1 =begin(x);

    int n = size(x);

    cout << n <<endl;

    auto p2 =end(x);

    //*p2=10; // runtime error

    // directory_iterator p ("C:/Window");
}