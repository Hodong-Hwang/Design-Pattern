#ifndef __INNERFACTORY_H_
#define __INNERFACTORY_H_
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

    class PointFactory{
        private:
        PointFactory(){};
        public:
        static Point NewCartesian(float x, float y)
        {
            return Point(x,y);
        }
        static Point NewPolar(float r, float theta)
        {
            return Point(r*cos(theta),r*sin(theta));
        }
    };    
    float x,y;
    public:
    static PointFactory Factory;

    /* data */
};

#endif