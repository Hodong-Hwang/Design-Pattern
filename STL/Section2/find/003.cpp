
// Generic Alorithm

#include <iostream>
#include <cstring>
template<typename T>
T* efind(T* first, T* last, T value)
{
    while(first !=last && *first !=value)
        ++first;
    
    return first == last? 0 :first;

}
using namespace std;
int main ()
{

    char s[] ="abcdefg";
    char* p =efind(s,s+4,'e');
    if (p==0)
    {
        cout << "fail" <<endl;
    }
    else
    {
        cout << "sucess" << *p <<endl;
    }
    double x[10]={1,2,3,4,5,6,7,8,9,10};

    double* p1 = efind(x,x+10,5.0);
    if (p1==0)
    {
        cout << "fail" <<endl;
    }
    else
    {
        cout << "sucess! :" << *p1 <<endl;
    }
    // double* p = efind(x,x+10,5); error
    
}