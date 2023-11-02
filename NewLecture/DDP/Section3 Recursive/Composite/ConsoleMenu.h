#pragma once
#include <memory>
#include <vector>
#include <iostream>
class CmdMenu
{
    std::string title;
public:
    CmdMenu(const std::string& s) : title(s) {}
    CmdMenu(const char* s) : title(s) {}

    std::string get_title() const { return title; }
    void set_title(const std::string& s) { title = s; }
    virtual void command() =0;
};
class MenuList : public CmdMenu
{
    std::vector<CmdMenu* > v;
public:
    MenuList(const std::string& title) : CmdMenu("MenuList") {}
    void add_Menu(CmdMenu* m) { v.push_back(m); }
    void command () override;
};

class ParticleGeneatorTester : public CmdMenu
{
public:
    ParticleGeneatorTester()
        : CmdMenu("ParticleGeneatorTester") {}
    void command() override;
}; 

class SurfaceExtracterTester : public CmdMenu
{
public:
    SurfaceExtracterTester()
        : CmdMenu("SurfaceExtracterTester") {}
    void command() override;
};

//template<typename T>
//inline void CmdMenu<T>::command()
//{
//    std::cout << get_title() << "is selected" <<std::endl;
//    static_cast<T*>(this)->command();
//}
