#include <mutex>

template <typename T>
class Singleton
{
    protected:
        //생성자는 기반 클래스에 존재하도록
        Singleton() {}
    private:
        Singleton (const Singleton&) = delete;
        Singleton& operator=(const Singleton&)=delete;

        static std::mutex m;
        static T* instance;
public :
    static T& get_instance()
    {   
        {
        std::lock_guard<std::mutex>g(m); // 생성자에서 m.lock();
        if(instance ==nullptr)
            instance = new T;
        // 소멸자에서 unlkock
        }
        return *instance;
    }

};
template<typename T> T* Singleton<T>::instance =nullptr;
template<typename T> std::mutex Singleton<T>::m ;

class Mouse : public Singleton<Mouse>
{

} ;

int main ()
{
    Mouse& c1 = Mouse::get_instance();
}
// 요새는 이렇게 안함.
// 요새는 Mayer single ton을 사용함.
