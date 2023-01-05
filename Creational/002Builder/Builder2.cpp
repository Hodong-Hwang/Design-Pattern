#include <string>
#include <sstream>
#include <vector>
using namespace std;
struct HtmlElement
{
    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;
    HtmlElement(){}
    HtmlElement(const std::string& name, const std::string& text):
    name(name),text(text){}
    std::string str (int indent =0) const
    {
        std::string str_;
        str_ = str_+"<"+name+">";
        str_ = str_+text;
        for (const auto& e:elements)
        {
            str_ = str_+"<"+e.name+">";
            str_ = str_ + e.text;
            str_ = str_+"</"+e.name+">";
        }
        str_ = str_+"</"+name+">";
        return str_;
    }
};//HtmlElement
struct HtmlBuilder
{
    HtmlElement root;
    HtmlBuilder(string root_name){root.name=root_name;}
    void add_child(string child_name,string child_text)
    {
        HtmlElement e{child_name,child_text};
        root.elements.emplace_back(e);
    }
    std::string str(){return root.str();}
};
void ex1()
{
    HtmlBuilder builder{"ui"};
    builder.add_child("li","hello");
    builder.add_child("li","World");
    printf(builder.str().c_str());
}
int main()
{
    ex1();
    return 0;
}