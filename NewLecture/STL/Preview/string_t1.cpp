#include <iostream>
#include <string>
#include <string.h>

int main()
{
    char cs1[10]="hello";
    char cs2[10];

    std::string s1 ="hello";
    std::string s2;
    strcpy(cs2,cs1);
    if( strcmp(cs1,cs2) )
    {
        std::cout << *cs1 <<std::endl;
    }
    s2=s1;
    if(s1==s2)
    {
        std::string s3;
        std::cout << s3 <<std::endl;
    }
    strcpy(cs2,s1.c_str());


}