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