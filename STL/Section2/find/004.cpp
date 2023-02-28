
// Generic Alorithm

#include <iostream>
#include <cstring>
template<typename T1, typename T2>
T1 efind(T1 first, T1 last, T2 value)
{
    while(first !=last && *first !=value)
        ++first;
    
    return first;
}

using namespace std;
int main ()
{
    double x[10]={1,2,3,4,5,6,7,8,9,10};

    double* p1 = efind(x,x+10,5);
    if (p1==p1+10)
    {
        cout << "fail" <<endl;
    }
    else
    {
        cout << "sucess! :" << *p1 <<endl;
    }
    
}