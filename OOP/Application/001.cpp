#include <iostream>
using namespace std;
class CWinApp;

CWinApp* g_app=nullptr;
class CWinApp
{
    public :
    CWinApp() {g_app=this;}
    virtual bool InitInstance() {return false;}
    virtual int  ExitInstance() {return false;}
    virtual int  Run() {return 0;}

};

int main ()
{
    if(g_app->InitInstance())
    {
        g_app->Run();
    }
    g_app->ExitInstance();
}

// ----------------------
// 사용자
// 1. 파생클래스 생성
// 2. 사용자 클래스 전역 객체 생성

class MyApp : public CWinApp
{
    public :
    virtual bool InitInstance()
    {
        cout <<"initalization" <<endl;
        return true;
    }
    virtual int  ExitInstance() 
    {
        cout <<"finish" <<endl;
        return 0;    
    }


};

MyApp theApp;