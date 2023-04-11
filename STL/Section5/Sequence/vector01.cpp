#include <vector>
#include <iostream>
#include "../../stltestero.h"


using namespace std;

void ex1()
{
      std::vector<int> v1;
    std::vector<int> v2 (10);
    std::vector<int> v3 (10,3);
    std::vector<int> v4 (v3);
    std::vector<int> v5{1,2,3,4};
    std::vector<int> v6={1,2,3,4};
    std::vector<int> v7(10,0);
    std::vector<int> v8{10,0};
    

    //v.push_front(10); //error
    v1.push_back(10);
    v1.push_back(20);
    v1.insert(begin(v1)+1,30);

    show(v1);

    int x[5]={1,2,3,4,5};
    v1.assign(x,x+5);

    show(v1);
}

void ex2()
{
    vector<int> v(10,0);
    v.resize(7);

    cout << v.size() <<endl
    << v.capacity() <<endl;

    v.pop_back();
    cout << v.size() <<endl
    << v.capacity() <<endl;

    v.shrink_to_fit();
    cout << v.size() <<endl
    << v.capacity() <<endl;

    v.push_back(0);
    cout << v.size() <<endl
    << v.capacity() <<endl;
}

void print (int* arr, int sz)
{
    for (int i =0; i<sz; i++)
    {
        cout <<arr[i] <<endl;
    }
}
void ex3()
{
    vector<int> v(10,0);
    print(&v[0],v.size());
    print(v.data(),v.size());

}
int main ()
{
  
    ex3();

}