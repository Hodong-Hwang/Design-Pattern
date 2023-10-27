// intent 
// 클래스로 캡슐화 하여 알고리즘을 대체하는 것이 의도임.
// 알고리즘읇 ㅏ꾸더라도 클라이언트는 아무런 변화가 없으.ㅁ
#include <iostream>
#include <string>
#include <conio.h>


class Edit
{
    std::string data;
public:
// 라이브러리 내부 코드를 바꿀 수 있도록 수정해주어야함.
    std::string get_text()
    {
        // std::cin >> data;
        // return data;
        data.clear();
        while (1)
        {
            char c = _getch();
            if(c==13) break;

            // 숫자만 입력받도록
            if(isdigit(c))
            {
                data.push_back(c);
                std::cout <<c;
            }
            std::cout <<"\n";
            return data;            
        }      
    }
};

int main()
{
    Edit edit;
    while (1)
    {
        std::string s = edit.get_text();
        std::cout << s <<std::endl;
    }
}