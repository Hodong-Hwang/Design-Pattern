#include <iostream>
#include <memory>


class Car
{
    int color;
    public:
    ~Car() {std::cout <<"~Car" <<std::endl; }
    void Go() {std::cout << "Go!" <<std::endl;}
};

