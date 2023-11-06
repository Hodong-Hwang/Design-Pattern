/*
[[Attributes 명령]]
[[nodiscard("reason")]]
c++ 표준에서 대표적인  nodisacard는 async함수가 ㅐ표적임.
*/
#include <future>
#include <thread>

int foo() {return 0;}

// Memory 누수를 방지하기 위함.
[[nodiscard("Memoery Leak may occur.")]]int* allocate (int size)
{
    return new int[size];
};

int main()
{
    allocate(10);// 메모리가 할당되었는데, 값을 안받음.
    // 메모리 누수가 발생함.
    //std::future<int> ret=
    std::async(std::launch::async,foo);
}