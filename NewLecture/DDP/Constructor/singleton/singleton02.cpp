#include <iostream>
#include <mutex>

void explain()
{
    std::cout << "Heap에 생성 시 해당 방법을 이용함." << std::endl;
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
        m.lock();
        if(instance ==nullptr)
        {
            instance = new Cursor;
        }
        m.unlock();
        return *instance;
    }

};
Cursor* Cursor::instance =nullptr;
std::mutex Cursor::m ;

int main()
{
    explain();
    Cursor& c1 = Cursor::get_instance();
    Cursor& c2 = Cursor::get_instance();

    std::cout << &c1 << "," << &c2 <<std::endl;

}