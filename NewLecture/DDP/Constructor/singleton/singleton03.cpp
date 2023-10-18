#include <iostream>
#include <mutex>
#include <locale>

void explain()
{
    std::cout << "singleton02에서 instance가 생성 되었음에도 m.lock이 Thread마다 불릴 수 있다." << std::endl;
    std::cout << "if loop를 추가하여 해당 상황을 방지하는 방법" << std::endl;
    std::cout << "DLCP (Double Check Locking Pattern)" <<std::endl;
    std::cout << "Compile 때문에 redordring 때문에 발생함." <<std::endl;

}
class Cursor
{
    private:
        Cursor() {}
        Cursor (const Cursor&) = delete;
        Cursor& operator=(const Cursor&)=delete;

        static std::mutex m;
        static Cursor* instance;
public :
    static Cursor& get_instance()
    {
        if(instance ==nullptr)
        {
            m.lock();
            if(instance ==nullptr)
                instance = new Cursor;
            m.unlock();

        }
        return *instance;
    }

};
Cursor* Cursor::instance =nullptr;
std::mutex Cursor::m ;

int main()
{
    std::setlocale(LC_ALL,"en_US.UTF-8");
    explain();
    Cursor& c1 = Cursor::get_instance();
    Cursor& c2 = Cursor::get_instance();

    std::cout << &c1 << "," << &c2 <<std::endl;

}