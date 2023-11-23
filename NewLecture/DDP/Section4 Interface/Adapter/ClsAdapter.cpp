#include <iostream>
#include "Shape.h"
#include "CoolText.h"
#include <vector>


class ClsAdapter : public CoolText, public Shape
{
    public:
    ClsAdapter(const std::string& text): CoolText(text){}
    // show라는 함수를 draw함수로 바꾼 것임.
    void draw() override {CoolText::show();}
};

class ObjAdapter : public Shape
{
    CoolText* ct;
public:
    ObjAdapter(CoolText* ct): ct(ct){}
    // show라는 함수를 draw함수로 바꾼 것임.
    void draw() override {ct->show();}
};
void ex2()
{
    std::vector <Shape*> v;
    CoolText ct("hello");
    v.push_back(new ObjAdapter(&ct));
    v[0]->draw();
    
}
int main()
{
    std::vector <Shape*> v;
    v.push_back(new ClsAdapter("Hello"));
    v[0]->draw();
}