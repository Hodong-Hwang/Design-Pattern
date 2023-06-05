#include <iostream>
#include <mutex>
using namespace std;


class Cursor
{
    int x,y;
    public:

    Cursor(const Cursor&)=delete;
    void operator=(const Cursor&)=delete;

    private :
    Cursor(){}
    static Cursor* pInstance;
    static mutex m;
    public:
    static Cursor& getInstance()
    {
        if(pInstance==0)
        {
            m.lock();
            if(pInstance==0)
            {
                pInstance= new Cursor;
                // 1. 메모맇 ㅏㄹㅇ당.
                // 2. 생성자 호출
                // 3. 주소 이동.

                // 컴파일러의 최적화 과정에서 문제가 발생할 수 있음.
                // Reorering 문제가 발생함. 
                // ReOrdering 하지 말라는 옵션을 주어야함. -> Atomic을 이용해서 해결해야함.
            }
            m.unlock();
        }
        return *pInstance;
    }
};

Cursor* Cursor::pInstance;
std::mutex Cursor::m;
int main ()
{
    Cursor& c1 =Cursor::getInstance();
    Cursor& c2 =Cursor::getInstance();
    std:: cout << &c1 << std::endl;
    std:: cout << &c2 << std::endl;


}