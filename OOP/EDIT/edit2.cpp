#include <iostream>
#include <string>
#include <conio.h> // getch()
struct IValidator
{
    virtual bool validate (std::string ,char c) = 0;
    virtual bool iscomplete(std::string s) {return true;}
    virtual ~IValidator(){}
};

class LimitDigitValidator : public IValidator
{
    int value;
    public:
    LimitDigitValidator (int n ): value(n){}
    virtual bool validate (std::string s,char c) override 
    {
        return s.size()< value &&isdigit(c);
    }
    virtual bool iscomplete(std::string s)
    {
        return s.size()==value;
    }
};

class Edit
{
    std::string data;
    IValidator* pval;
    public : 
    void SetValidator(IValidator * p ) {pval=p;}

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
           if (c==13 && (pval ==0 || pval->iscomplete(data)))  break;// enter
           if (pval == 0 || pval->validate(data,c))
           {
                data.push_back(c);
                std::cout<<c;
           }
        }
        std::cout<<std::endl;
        return data;
    }
};

int main()
{
    Edit edit;
    LimitDigitValidator v(5);

    edit.SetValidator(&v);

    while (1)
    {
        std::string s=edit.getData();
        std::cout << s <<std::endl;
    }
}