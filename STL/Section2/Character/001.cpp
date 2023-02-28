#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename T>
void print(T& c)
{
    typename T::value_type n =c.front();
    cout << n <<endl;
}
// template <typename T>
// void print(vector<T>& c)
// {
//     T n =c.front();
//     cout << n <<endl;
// }

int main ()
{
    vector<double> v ={1,2,3}; 
    print(v);
}