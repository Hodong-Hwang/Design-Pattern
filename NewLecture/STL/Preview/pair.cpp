#include <iostream>
#include <utility>
using namespace std;
int main()
{
    pair <int, double> p1(1,3.4);
    cout << p1.first << "," << p1.second << endl;
}

// make_pair가 중요함
// tuple => pair보다 일반화된 tyhpe
// 서로 다른 타입의 객체를 N개 보관하는 타입.
// 함수가 2개의 값을 return 할떄 pair를 return함.
