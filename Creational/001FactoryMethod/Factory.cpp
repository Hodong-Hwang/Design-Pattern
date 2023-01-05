#include "Factory.h"

int main()
{
    float x,y,r,theta;
    x=0.5;
    y=0.5;
    r=1;
    theta=45;
    auto cartptr=PointFactory::NewCartesian(x,y);
    auto poloarptr=PointFactory::NewPolar(r,theta);
    cartptr.print_XY();
    poloarptr.print_XY();
    return 0;
}