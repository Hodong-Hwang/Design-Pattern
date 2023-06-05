#include <iostream>

using namespace std;

struct IEdit
{
    virtual void Draw()=0;
    virtual ~IEdit() {}
};

struct IButton
{
    virtual void Draw()=0;
    virtual ~IButton(){};
};

struct WinButton :public IButton {void Draw() {cout << "Draw WinButton"<<endl;}};
struct GTKButton :public IButton {void Draw() {cout << "Draw WinButton"<<endl;}};
struct WinEdit :public IEdit {void Draw() {cout << "Draw WinEdit"<<endl;}};
struct GTKEdit :public IEdit {void Draw() {cout << "Draw GTKEdit"<<endl;}};


struct IFactory
{
    virtual IButton* CreateButton()=0;
    virtual IEdit* CreateEdit()=0;

};

struct WinFactory
{
    WinButton* CreateButton() {return new WinButton;}
    WinEdit* CreateEdit() {return new WinEdit;}
};

struct GTKFactory
{
    GTKButton* CreateButton() {return new GTKButton;}
    GTKEdit* CreateEdit() {return new GTKEdit;}
};


int main (int argv, char** argc)
{
    IButton *pBtn;
}