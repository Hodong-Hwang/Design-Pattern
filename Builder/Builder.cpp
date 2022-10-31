
#include <string>
#include <sstream>
#include <vector>
void ex1()
{
    using namespace std;
    string words[]={"Hello","World"};
    std::ostringstream oss;
    oss<< "<ul>";
    for(auto w:words){
        oss <<" <li>" << w <<"</li>";
    }
    oss<<"</ul>";
    printf(oss.str().c_str());
}

struct HtmlElement
{
    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;
    HtmlElement(){}
    HtmlElement(const std::string& name, const std::string& text):
    name(name),text(text){}
    std::string str (int indent =0) const{
        // add more

    }

};//HtmlElement

void senario()
{
    using namespace std;
    string words[]={"Hello","World"};
    HtmlElement list{"ul",""};
    for(auto w:words){
        list.elements.emplace_back(HtmlElement{"li",w}); 
    }
    printf(list.str().c_str());
}
int main()
{
    senario();
    return 0;
}