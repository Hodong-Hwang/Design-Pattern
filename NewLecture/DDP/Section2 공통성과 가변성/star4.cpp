// 변하는 코드를 분리하는 방법
// 변하는 코드를 가상함수로 분리
// 변하는 코드를 다른 클래스로 분리
// A B C validtaion 정책을 담은 다양한 클래스
// Interface를 가지고 있어야함.
// 동적으로 변환이가능함.
#include <iostream>
#include <string>
#include <conio.h>

struct IValidator
{
    virtual bool validate(const std::string& data, char c)=0;
    virtual bool iscomplete(const std::string& data) {return true;}
};

class DigitValidator : public IValidator
{
    int count;
public:
    DigitValidator(int count=9999) : count(count){}
    bool validate(const std::string& data, char c){
        return data.size() <count && isdigit(c);
    }
    bool iscomplete(const std::string& data) {return count!=9999 && data.size()==count;}

    
};

class Edit
{
    std::string data;
    IValidator* val = nullptr;
public:
// 라이브러리 내부 코드를 바꿀 수 있도록 수정해주어야함.
    void set_Validator(IValidator* p) {val=p;}
    std::string get_text()
    {
        // std::cin >> data;
        // return data;
        data.clear();
        while (1)
        {
            char c = _getch();
            if(c==13 && (val==nullptr ||val->iscomplete(data))) break;

            // if가 원하느조건에 따라 바뀌도록 수정
            if(val==nullptr || val->validate(data,c))
            {
                data.push_back(c);
                std::cout <<c;
            }
        }      
        std::cout <<"\n";
        return data;           
    }
};

int main()
{

    Edit edit;
    DigitValidator v(5);
    edit.set_Validator(&v);
    while (1)
    {
        std::string s = edit.get_text();
        std::cout <<s <<std::endl;
    }

}