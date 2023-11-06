#include <iostream>

// no_unqiue가 없는 경우 EBCO 기술이 사용됨.
// 핵심은 1byte가 추가됨으로써 4byte씩 추가됨 ( 기술적인 문제)
template <typename T, typename U> struct PAIR
{
    [[no_unique_address]]T first;
    [[no_unique_address]]U second;
    template <typename A, typename B>
    PAIR(A&& a, B&& b) : first(std::forward<A>(a), std::forward<B>(b)) {};
};


template <typename A, typename B> PAIR(A&& a, B&& b)->PAIR<A,B>;

int main()
{
    PAIR p(malloc(100),[](void* p){free(p);});
    // 캡처 하지 않는class는 empty class임
    std::cout << sizeof(p) <<std::endl;
    // l람
}