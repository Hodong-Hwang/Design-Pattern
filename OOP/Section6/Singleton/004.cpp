#include <iostream>

using namespace std;


// SingleTon  재사용 기술

#define MAKE_SINGLETON(classname)               \
private :                                       \
    classname(){}                               \
    classname(const classname&)=delete ;        \
    void operator=(const classname&)= delete;    \
public:                                         \
    static classname& getInstance()             \
    {                                           \
        static classname instance;              \
        return instance;                        \
    }                                           \


class Cursor
{
    int x,y;
    MAKE_SINGLETON(Cursor)
};

class Mouse : public Cursor
{

};

int main()
{
    Cursor& c1 =Cursor::getInstance();
}