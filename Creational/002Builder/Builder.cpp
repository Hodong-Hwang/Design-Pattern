
#include <string>
#include <sstream>
#include <vector>
#include <memory>

class HtmlBuilder;
class HtmlElement
{
    public:
    std::string tag;
    std::string text;
    std::vector<HtmlElement> elements;
    static std::unique_ptr<HtmlBuilder> build(const std::string root_name){
        return std::make_unique<HtmlBuilder>(root_name);
    }
    std::string str () const
    {
        std::string str_;
        str_ = str_+"<"+tag+">\n";
        str_ = str_+text;
        for (const auto& e:elements)
        {
            str_ = str_+"\t<"+e.tag+">";
            str_ = str_ + e.text;
            str_ = str_+"</"+e.tag+">\n";
        }
        str_ = str_+"</"+tag+">";
        return str_;
    }
    private:
    HtmlElement(){};
    HtmlElement(std::string tag_, std::string text_):
    tag(tag_),text(text_){}
    friend class HtmlBuilder;
};
class HtmlBuilder
{
    public:
    HtmlBuilder(std::string root_name){ root.tag = root_name; }
    HtmlElement root;
    HtmlBuilder* add_child(std::string child_name, std::string child_text){
    HtmlElement e{ child_name, child_text };
    root.elements.emplace_back(e);
    return this;
    }
    std::string str(){return root.str();}
};
int main()
{
    auto builder=HtmlElement::build("ui");
    builder->add_child("li","hello")->add_child("li","World");
    printf(builder->str().c_str());
    return 0;
}