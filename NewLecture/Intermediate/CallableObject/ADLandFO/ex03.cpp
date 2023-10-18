#include <iostream>
namespace mystd
{
    class string {};

    template <typename T>
    void max (const T& a, const T& b) {std::cout <<"std::max" <<std::endl;}

    namespace ranges
    {
        struct max_fn
        {
            template <typename T>
            void operator() (const T&, const T& b){std::cout <<"std::range::max"<<std::endl;}
        };
        max_fn max;
    }
}


int main ()
{
    mystd::string s1,s2;

    mystd::max(s1,s2);

    mystd::ranges::max(s1,s2);

    using namespace mystd::ranges; // 사용하는 경우 error
    max(s1,s2); // 함수 객체를 사용함에 따라서 에러를 방지함.
    // C++ 20을 가지고 있는 알고리즘은 함수 객체를 가지고 있음. 

}