#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

class MenuItem
{
    std::string title;
    int id;
public:
    MenuItem(const std::string& title, int id)
    : title(title), id(id){}
    std::string get_title() const {return title;}
    void set_title(const std::string& s) {title=s;}
    void command()
    {
        std::cout<<get_title() << "is Selected " <<"\n";
        _getch();
    }
};

class PopupMenu
{
    std::string title;
    std::vector<MenuItem*> v;
public:
    PopupMenu(const std::string& title) : title(title){}
    void add_Menu(MenuItem* m){v.push_back(m);}
    void command()
    {
        while(1)
        {
            system("cls");
            std::size_t sz=v.size();
            std::size_t i = 0;
            for (MenuItem* p : v)
            {
                std::cout << ++i <<". " << p->get_title() <<"\n";
            }
            std::cout << i+1 <<". end  \n";
            std::cout << "Select Menu >> ";

            int cmd;
            std::cin>>cmd;
            if(cmd==sz +1)
                break;
            
            if(cmd<1 || cmd>sz+1)
                continue;
            v[cmd-1]->command();

        }


    }
};
// Popupmenu

int main()
{
    MenuItem m1("gigmbab",11);
    MenuItem m2("RM",11);

    //m1.command();//김밥을 선택
    PopupMenu pm ("today's Menu");
    pm.add_Menu(&m1);
    pm.add_Menu(&m2);

    pm.command();
    //Popup 메뉴 선택했을 때 하위 메뉴를 열어줌


}
// 위 개념을 객체지향으로 변경