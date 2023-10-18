#include <iostream>
namespace mystd
{
    class string {};

    template <typename T>
    void max (const T& a, const T& b) {std::cout <<"std::max" <<std::endl;}

    namespace ranges
    {
        template <typename T>
        void max (const T& a, const T& b) {std::cout <<"std::ranges::max" << std::endl;}
    }
}


int main ()
{
    mystd::string s1,s2;

    mystd::max(s1,s2);

    mystd::ranges::max(s1,s2);

    using namespace mystd::ranges; // 사용하는 경우 error
    max(s1,s2);

}