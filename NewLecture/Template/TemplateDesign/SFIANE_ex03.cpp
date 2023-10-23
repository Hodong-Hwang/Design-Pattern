#include <iostream>
#include <type_traits>


template <typename T>
void printsv_impl(const T& v, std::true_type)
{
    std::cout << v << ":" << * v << std::endl;
}

template <typename T>
void printsv_impl(const T& v, std::false_type)
{
    std::cout << v << std::endl;    
}

template <typename T>
void printvs(const T& v)
{
    printsv_impl (v,std::is_pointer<T>());
}

// c++17
template <typename T> void printv(const T& v)
{
    if constexpr(std::is_pointer<T>::value)
    {
        std::cout << v << ":" << * v << std::endl;
    }
    else
    {
        std::cout << v << std::endl;    
    }
}

//pointer 일때만 생성
// enable_if에 대해서 void만 생성되는 거만 이용하게 된다면 다음과 같은 기술들이 사용간으함.
// SFIANE을 이용함.  void return 을 하기 때문에 enable_if를 사용. 만약 아닌경우 코드생성 X
template <typename T>
typename std::enable_if<std::is_pointer<T>::value>::type printvs2(const T& v)
{
    std::cout << v << ":" << * v << std::endl;
}

template <typename T>
typename std::enable_if<!std::is_pointer<T>::value>::type printvs2(const T& v)
{
    std::cout << v << std::endl;    
}

int main ()
{
    int n=0;
    printv(n);
    printv(&n);
    printvs(n);
    printvs(&n);
    printvs2(n);
    printvs2(&n);
}
