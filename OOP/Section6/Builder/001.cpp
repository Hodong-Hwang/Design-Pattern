#include <iostream>
#include <string>


using APPLICATION = std::string;


class Director
{
    std::string name = "HONG";
    std::string phone = "0100000000";
    std::string address = "SEOUL SONGPA";
public:
    APPLICATION construct()
    {
        APPLICATION app;
        app += name + "\n";
        app += phone + "\n";
        app+= address  +"\n";
        return app;
    }
    APPLICATION XMLconstruct()
    {
        APPLICATION app;
        app += "<NAME>" +name + "</NAME>\n";
        app += "<PHONE>" +phone + "</PHONE>\n";
        app+= "<ADDRESS>" +address  +"</ADRESS>\n";
        return app;
    }
};

int main ()
{
    Director d;
    APPLICATION app =d.construct();
    std::cout<< app << std::endl;
}