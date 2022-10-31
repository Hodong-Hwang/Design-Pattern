#include <stdio.h>
#include <string>
#include <memory> 
#include <iostream> 

#define MACROCONCAT(token) \
    void token##MACROCONCAT() \
    {                      \
        printf("this is funciton for %s\n",#token); \
    }\

#define FACTORY(token) \
    std::shared_ptr<token> token##FACTORY() \
    {                      \
       return std::make_shared<token>(); \
    }\

MACROCONCAT(int);
MACROCONCAT(double);

class TempA
{
public:
    TempA(){}
    std::string ClassName="TempA";
};

class TempB
{
public:
    TempB(){}
    std::string ClassName="TempB";
};
FACTORY(TempA);
FACTORY(TempB);

int main(int argc, char** argv)
{
    intMACROCONCAT();
    doubleMACROCONCAT();
    auto a= TempAFACTORY();
    auto b= TempBFACTORY();
    std::cout << a->ClassName <<std::endl;
    std::cout <<b->ClassName <<std::endl;

    return 0;
}