#include <iostream>
// [first,last)
// Character-> 모든 Type에배열로 확장하자.
template<typename T>
T* efinder (T* first, T* last, T value)
{
    while (first!=last && *first !=value)
    {
        first++;
    }
    return first == last ? 0: first;

}
int main()
{
    double d[10]{1,2,3,4,5,6,7,8,9,10};
    double* p =efinder(d,d+10,5.0); // 함수는 인자를 알아서 추정함.
    //double* p2 =efinder(d,d+10,5); // error ... 발생


    if( p==0)
    {
        std::cout << "fail" << std::endl;
    }
    else
    {
        std::cout <<"sucess : " << * p <<std::endl;
    }
}