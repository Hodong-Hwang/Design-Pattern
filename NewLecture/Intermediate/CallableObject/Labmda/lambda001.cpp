

// lambda > function object
// auto 처럼 함수 처럼 사용하는 것 가능함.
// 람다 표현식을 변환하는 함수. querying..


#include <iostream>
#include <vector>
#include <algorithm>


int main ()
{
    std::vector v{2,4,6,8, 10};

    std::sort (v.begin(),v.end(),[](int a, int b){return a>b;});

}