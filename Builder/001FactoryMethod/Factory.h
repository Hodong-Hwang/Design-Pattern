#ifndef __FACTORY_H_
#define __FACTORY_H_
#include <cmath>
#include <iostream>
class PointFactory;
class Point
{
    public:
    void set_X(float x_){x=x_;}
    void set_Y(float y_){y=y_;}
    void print_XY(){std::cout << "x=" <<x <<",\t" <<"y=" <<y << std::endl;}
    private:
    Point(float x_, float y_):x(x_),y(y_){};
    friend class PointFactory; 
    // 생성자 접근 허용을 위함.
    // Point Factory를 이용한 생성
    float x,y;

    /* data */
};

class PointFactory
{
    public:
    static Point NewCartesian(float x, float y)
    {
        return Point(x,y);
    }
    static Point NewPolar(float r, float theta)
    {
        return Point(r*cos(theta),r*sin(theta));
    }
    private:
    PointFactory(){};

};

#endif