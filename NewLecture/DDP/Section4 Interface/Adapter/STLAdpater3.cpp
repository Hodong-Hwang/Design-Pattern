#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;
// 3. 포함을 사용한 stack adapter
// 2와 3의 차이. 
// 상속의 경우는 override할 수 있는 기회가 있음.
// 3번은 무조건 이전의 함수만을 이용하여야함.

template <typename T> 
class stack
{
    std::list<T> c;
public:
    void push(const T& a)
    {
        c.push_back(a);
    }
    void pop()
    {
        c.pop_back();
    }
    T& top()
    {
        return c.back();
    }
    //단점은 -> stack에 대해서 모든 함수를 상속받게됨.
    // 좋지 않은 바람직 하지않음.
};

int main()
{
}