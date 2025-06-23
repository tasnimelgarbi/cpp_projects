#include "cylinder.h"
#include <iostream>
using namespace std;

Cylinder::Cylinder()
{
    height=0;
}
Cylinder::Cylinder(double h,double r)
{
    height=h;
    radius=r;
}
Cylinder::Cylinder(const Cylinder&cy)
{
    height=cy.height;
}
void Cylinder::setcylinder(double h)
{
    height=h;
}
double Cylinder::getheight()const
{
    return height;
}
double Cylinder::getvolume()const
{
    return 3.14*radius*radius*height;
}
Cylinder::~Cylinder()
{

}
void printcylinder(const Cylinder&ptr)
{
    cout<<"the volume of cylinder= :"<<ptr.getvolume()<<endl;
}
