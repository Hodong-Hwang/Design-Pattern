#include <iostream>
// c++filt -t
template <typename T> void foo (T arg)
{
    // type id -> const , volatile 이 안들어옴.
    std::cout <<typeid(T).name() <<std::endl;
   // std::cout <<__FUNCTION__ <<std::endl;
    // std::cout <<__PRETTY_FUNCTION__ <<std::endl;
    // std::cout <<__FUNCSIG__ <<std::endl;

}
/// ... 의도적 error

// compiler가 제공하는 매크로르 사용


int main ()
{
    int n =10 ;
    foo(n);
    //template -> auto sma deductiopn
    // decltype -> different
    foo<const int&> (n);

}