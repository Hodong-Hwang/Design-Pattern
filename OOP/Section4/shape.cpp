#include <iostream>
#include <vector>
using namespace std;
class TextView
{
    std::string data;
    std::string font;
    int width;
    public:
    TextView(std::string s, std::string fo="NaNo", int w =24):data(s),font(fo),width(w){}
    void Show() {std::cout <<data <<std::endl;}
};

// Adapater Pattern another class
class Text : public TextView, public Shape
{
    public:
    Text(string s) : TextView(s){}

    virtual void Draw(){TextView::Show();}
};

class Shape
{
    public:
    virtual void Draw(){cout<< "Draw Shape"<<endl;}
};

class Rect :public Shape
{
    public:
    virtual void Draw(){cout<< "Draw Rect"<<endl;}
};

class Circle :public Shape
{
    public:
    virtual void Draw(){cout<< "Draw Circle"<<endl;}
};

int main ()
{
    return 0;
}