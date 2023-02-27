#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BaseMenu
{
    string title;
    public:
    BaseMenu(string s) : title (s) {}
    string get_Title() const {return title;}

    virtual void command() = 0 ; // !!
};

class MenuItem : public BaseMenu
{
    int id;
public:
    MenuItem(string s, int n):BaseMenu(s), id(n){}

    virtual void command() override
    {
        cout << get_Title() <<endl;
        getchar();
    }
};
class PopUpMenu : public BaseMenu
{
    vector <BaseMenu*> v;
public:
    PopUpMenu(string s):BaseMenu(s){}
    void addMenu(BaseMenu* p) { v.push_back(p);}
    
    virtual void command() override
    {
        while (1)
        {
            system("cls");

            int sz =v.size();

            for (int i = 0; i < sz ; i ++)
            {
                cout << i+1  << ". "<< v[i] ->get_Title() <<endl;
            }
            cout << sz+1 << ". goto upper menu" <<endl;
            int cmd ;
            cout << "select menu >> " ;
            cin >>cmd;
            if (cmd <1 || cmd>sz+1) continue;            
            if (cmd ==sz+1)  break;
            v[cmd-1]->command(); /// polymorphic을 이용함. (다형성을 이용한 방법에 해당함.)

        }

    } 
};
int main ()
{
    MenuItem m("sound",11);

    PopUpMenu* memnubar = new PopUpMenu("MenuBar");
    PopUpMenu* pm1 = new PopUpMenu("Set Display Opt");
    PopUpMenu* pm2 = new PopUpMenu("Set Audio Opt");
    MenuItem* m1 = new MenuItem("Check Information" , 1);

    memnubar->addMenu(pm1);
    memnubar->addMenu(pm2);
    memnubar->addMenu(m1);
    pm1->addMenu(new MenuItem("Change Display",21));
    pm1->addMenu(new MenuItem("Change Constrast",21));
    pm2->addMenu(new MenuItem("Change Audio Volume",31));

    memnubar->command();

}