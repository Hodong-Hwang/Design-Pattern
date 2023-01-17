#include <iostream>
#include <exception>
// 하나만 존재하는 경우 사용하는 패턴 (Turn on, Turn off 와 같은)
// 메모리 낭비를줄 줄ㅇ ㅣㄹ 수 있음.


struct DataBase
{
    DataBase()
    {
        static int instance_count{0};
        if(++instance_count>1)
            throw std::exception ("Cannot make > 1 database!" );
            // 사용자에 의해 문제가 발생할 수 있는 여지가 있다.
        //생성자를 숨겨서, 관리할 수 있는 방법들을 이용할 수 있다.
    }
    // get 함수에서 힙메모리 할당으로 객체를 생성하는 방법이 존재할 수 있따.
    static DataBase& get()
    {
        static DataBase* database = new DataBase();
        return *database;
    }
};



static DataBase database{};
// Static의 경우 컴파일러에서 초기화 순서가 정해져 있지 않음. 이에 문제가 발생할 수 있는 여지가 있다.
// 해당 문제를 방지하기 윟새ㅓㄴ느 쓰레드 락을 걸어주어야 함.

