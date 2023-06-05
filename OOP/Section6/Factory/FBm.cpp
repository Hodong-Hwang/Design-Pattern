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

class WinDialog
{
    public:
    void Init()
    {
        WinButton* pBtn = new WinButton;
        WinEdit* pEdit = new WinEdit;

        pBtn->Draw();
        pEdit->Draw();
    }
};

class GTKDialog
{
    public:
    void Init()
    {
        GTKButton* pBtn = new GTKButton;
        GTKEdit* pEdit = new GTKEdit;

        pBtn->Draw();
        pEdit->Draw();
    }
};
