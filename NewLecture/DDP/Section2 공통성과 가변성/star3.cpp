#include <iostream>
#include <string>
#include <conio.h>
//파생클래스를 이용하는 것임.
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
            if(c==13 && iscomplete(data)) break;

            // if가 원하느조건에 따라 바뀌도록 수정
            if(validate(data,c))
            {
                data.push_back(c);
                std::cout <<c;
            }
        }      
        std::cout <<"\n";
        return data;            

    }
    virtual bool validate(const std::string& data, char c)
    {
        return true;
    }
    virtual bool iscomplete(const std::string& data)
    {
        return true;
    }
};

class NumEdit : public Edit{
    int count;
public:
    NumEdit(int count=9999):count(count){}
    bool validate (const std::string& data, char c) override
    {
        return data.size() <count && isdigit (c);
    }
    bool iscomplete(const std::string& data) override
    {
        return count !=9999 && data.size()==count;
    }
};

int main()
{
    NumEdit edit(5);
    while (1)
    {
        std::string s = edit.get_text();
        std::cout << s <<std::endl;
    }
}