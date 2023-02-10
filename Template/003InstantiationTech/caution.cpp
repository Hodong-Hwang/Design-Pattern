#include <iostream>

using namespace std;

template <typename T> T square (T a)
{
    return a* a;
}

int main ()
{
   // printf("%p\n", &square); //error
    printf("%p\n", &square<int>); //ok

}