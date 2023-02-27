#include <iostream>
#include <string.h>
#include <string>

using namespace std;


int main ()
{
    string s1= "hello";
    char s2[10];
    string s3;
    s3=s1;

    strcpy(s2,s1.c_str()); // s1.data() = s1.c_str()

}