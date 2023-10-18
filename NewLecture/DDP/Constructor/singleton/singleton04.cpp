#include <iostream>
#include <mutex>
#include <locale>

void explain()
{
    std::cout << "lock과 unlock을 직접쓰는건 좋지 않음." << std::endl;
    std::cout << "예외 발생 시 unlock을 보장할 수 없다." <<std::endl;
    std::cout << "이에 lockguard를 사용하는 것을 추천" <<std::endl;

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
        {
        std::lock_guard<std::mutex>g(m); // 생성자에서 m.lock();
        if(instance ==nullptr)
            instance = new Cursor;
        // 소멸자에서 unlkock
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