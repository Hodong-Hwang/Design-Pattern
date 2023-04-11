
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>


void foo (int& a)
{
    //std::cout << a << std::endl;
    a= a*2;
}

struct Show
{
    std::string sep;
    std::ostream& os;
    Show(std::ostream& o =std::cout , std::string s="\n"):os(o),sep(s){};
    void operator() (int a) const{
        os << a <<sep;
    }
};

int main ()
{
    std::vector<int> v(10);
    std::iota(v.begin(),v.end(),0);
    // function
    for_each(begin(v),end(v),foo);
    Show s(std::cout,"\t");
    // function object
    for_each(begin(v),end(v),s);

    // lambda expression
    for_each(begin(v),end(v),[](int a){std::cout << a<<std::endl;});

    return 0;

}