#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;
// 3. 포함을 사용한 stack adapter
// 포함에서 Vector인지 아니면 List를 쓸건지를 선택할 수 있도록 변경
// 단위 전략을 정의해서 교체해보자.
// stack은 어떠한 adapter인가?
// C* 이라면 object adpater임
// 하지만 C 인경우 class Adapter로 봐야함.
template <typename T, typename C=std::deque<T>> 
class stack
{
    C c;
public:
    constexpr void push(const T& a)
    {
        c.push_back(a);
    }
    constexpr void pop()
    {
        c.pop_back();
    }
    constexpr T& top()
    {
        return c.back();
    }
    //단점은 -> stack에 대해서 모든 함수를 상속받게됨.
    // 좋지 않은 바람직 하지않음.
};

int main()
{
    stack<int, std::vector<int>> s1;
    stack<int> s2;

}