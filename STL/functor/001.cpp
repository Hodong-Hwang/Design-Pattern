#include <iostream>
using namespace std;

struct Plus
{
    int operator ()(int a, int b) const{
        return a+b;
    }
};
// () 
// 1. 함수
// 2. 함수 포인터
// 3. ()를 재정의한 클래스
// 4. 람다 표현식


int main ()
{
    Plus p;
    int n = p (1,2);
    cout << n <<endl;

    // a + b; a.operator+(b)
    // a - b; a.operator-(b)
    // a();  a.operator()();
    // a.operattor()(1,2)

}