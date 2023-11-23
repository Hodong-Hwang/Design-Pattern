#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;
// 2. Private 상속을 이용한 adapter
// list로 물려 받은 것은 모두 Private로 받는다.
// -> 필요 한 함수만 public 으로 들 수 있음.
// 구현은 물려받지만 인터페이스는 물려받지 않음.
template <typename T> 
class StackAdapter : private std::list<T>
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