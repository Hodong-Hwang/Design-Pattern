#include "InnerFactory.h"
int main()
{
    float x,y,r,theta;
    x=0.5;
    y=0.5;
    r=1;
    theta=45;
    auto cart=Point::Factory.NewCartesian(x,y);
    auto polar=Point::Factory.NewPolar(r,theta);
    
    cart.print_XY();
    polar.print_XY();
    return 0;

}

