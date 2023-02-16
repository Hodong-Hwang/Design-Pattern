#include<iostream>
struct A
{
    int x;
    void fa() {std::cout <<this <<std::endl;}
};
struct B
{
    int y;
    void fb() {std::cout <<this <<std::endl;}

};
struct C :public A, public B
{
    int z;
    void fc() {std::cout <<this <<std::endl;}

};

int main ()
{
    C cc;
    cc.fa();
    cc.fc();
    cc.fb();
    void(C::*f)(); //(&cc + f.this_offset)
    // f has this offset
    std::cout <<sizeof(f) <<std::endl;


   // void * p = f; //error
    return 0;
}