#include <iostream>
#include <string>

using namespace std;

int main ()
{
    std::string s1 ="abcd";
    std::string s2 = "ABCD";

    if(s1==s2)
    {
        std::cout <<"same" <<std::endl;
    }
    else{
        std::cout << "not same" << std::endl;
    }
}