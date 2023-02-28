
// Generic Alorithm

#include <iostream>
#include <cstring>
// [first, last) hlaf open ragne
char* estchar(char* first, char* last, char value)
{
    while(first !=last && *first !=value)
        ++first;
    
    return first == last? 0 :first;

}
using namespace std;
int main ()
{
    char s[] ="abcdefg";
    char* p =estchar(s,s+4,'e');
    if (p==0)
    {
        cout << "fail" <<endl;
    }
    else
    {
        cout << "sucess" << *p <<endl;

    }
}