#include <iostream>

using namespace std;


class Cursor
{
    int x,y;
    public:

    Cursor(const Cursor&)=delete;
    void operator=(const Cursor&)=delete;

    private :
    Cursor(){}
    static Cursor instance;

    public:
    static Cursor& getInstance()
    {
        return instance;
    }
};

Cursor Cursor::instance;
int main ()
{
    Cursor& c1 =Cursor::getInstance();
    Cursor& c2 =Cursor::getInstance();

    std:: cout << &c1 << std::endl;
    std:: cout << &c2 << std::endl;


}