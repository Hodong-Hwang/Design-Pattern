#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;


void ex1()
{
    double distance = 3;
    duration<double ,ratio<1,1> > d1(3); // 3m
    duration<double, ratio<1,1000>> d2 (d1); // milli 3000

    cout << d2.count() <<endl;

    duration <double, ratio <1000,1>>d3(d1); //km;
    duration<double, milli> d4 (d1); // milli 3000
    duration<double, kilo> d5 (d1); // milli 3000

    cout <<d3.count() <<endl; // 9.003
    // data 손실이 있는 경우 - > duraction_cast로 수행함
    // 버림인지, 반올림 여부는 함수 여부로 가능함. c++ 17부터 제공하고 있음
}

int main()
{
    ex1();
}