#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;
// 1. 상속을 이용한 adapter
template <typename T> 
class StackAdapter : public std::list<T>
{
public:
    void push(const T& a)
    {
        std::list<T>::push_back(a);
    }
    void pop()
    {
        std::list<T>::pop_back();
    }
    T& top()
    {
        return std::list<T>::back();
    }
    //단점은 -> stack에 대해서 모든 함수를 상속받게됨.
    // 좋지 않은 바람직 하지않음.
};

int main()
{
}