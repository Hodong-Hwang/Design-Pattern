#include <iostream>
#include <string>
#include <conio.h> // getch()
class Edit
{
    std::string data;
    public : 

    virtual bool validate(char c)
    {
        return isdigit(c);
    }
    std::string getData()
    {
        data.clear();
        while (1)
        {
           char c= getch();
           if (c==13)  break;// enter
           if (validate(c))
           {
                data.push_back(c);
                std::cout<<c;
           }
        }
        std::cout<<std::endl;
        return data;
    }
};

class Address: public Edit
{
    virtual bool validate(char c)
    {
        return true;
    }
};

int main ()
{
    Edit edit;
    while (1)
    {
        std::string s = edit.getData();
        std::cout << s<<std::endl;
    }
}