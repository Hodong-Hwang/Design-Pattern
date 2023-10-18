#include <iostream>

void explain()
{
    std::cout <<  "singleton Pattern" <<std::endl;
    std::cout << "intent : " << "\t" << " 인스턴스는 오직 하나임을 보장 및 동일한 방법으로 접근을 위함 " <<std::endl;
    std::cout << " 전역변수와 유사한 단점이 존재 " <<std::endl;
    std::cout << "생성 규칙 1 : priavte 생성자 " <<std::endl;
    std::cout << "생성 규칙 2 : 한개의 객체는 만들 수 있도록 (static 선언) " <<std::endl;
    std::cout << "생성 규칙 3 : 복사 생성자 사용 X -> 복사/대입 금지 (=delete) " <<std::endl;
    std::cout << "Mayer's singleton = 오직 한개의 객체를 static 지역 변수를 선언" <<std::endl;
    std::cout << "지연된 초기화 >> getinstance 선언 시 호출" <<std::endl;
    std::cout << "thread safe" <<std::endl;

}
class Cursor
{
    private:
        Cursor() {}
        Cursor (const Cursor&) = delete;
        Cursor& operator=(const Cursor&)=delete;
public :
    static Cursor& get_instance()
    {
        static Cursor instance;
        return instance;
    }

};


int main()
{
    Cursor& c1 = Cursor::get_instance();
    Cursor& c2 = Cursor::get_instance();

    std::cout << &c1 << "," << &c2 <<std::endl;

}