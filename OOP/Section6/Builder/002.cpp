#include <iostream>
#include <string>
using APPLICATION = std::string;

struct IBuilder
{
    virtual ~IBuilder() {}
    virtual void makeName(std::string name ) = 0;
    virtual void makeAddress(std::string address ) = 0;
    virtual void makePhone(std::string phone ) = 0;
    virtual APPLICATION getResult() = 0;
};


class XMLBuilder : public IBuilder{
    APPLICATION app;
    public:
    virtual void makeName(std::string name )
    {
        app += "<NAME>" + name +"</NAME>\n";
    }
    virtual void makeAddress(std::string address )
    {
        app += "<address>" + address +"</address>\n";
    }

    virtual void makePhone(std::string phone )
    {
        app += "<phone>" + phone +"</phone>\n";
    }
    APPLICATION getResult() {return app;}

};

class Director
{
    std::string name = "HONG";
    std::string phone = "0100000000";
    std::string address = "SEOUL SONGPA";
    IBuilder* pBuilder;
public:
    void setBuilder(IBuilder* p){pBuilder = p;}
    APPLICATION construct()
    {
        pBuilder->makeName(name);
        pBuilder->makeAddress(address);
        pBuilder->makePhone(address);
        return pBuilder->getResult();
    }

};

int main ()
{
    Director d;
    XMLBuilder xb;
    d.setBuilder(&xb);
    APPLICATION app =d.construct();
    std::cout <<app <<std::endl;
    return 0;

}