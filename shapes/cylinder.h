#ifndef CYLINDER_H
#define CYLINDER_H
#include "circle.h"
#include "shape.h"

class Cylinder :public Circle
{
public:
    Cylinder();
    Cylinder(double,double);
    Cylinder(const Cylinder&cy);
    void setcylinder(double);
    double getheight()const;
    double getvolume()const;
    ~Cylinder();
    friend void printcylinder(const Cylinder&ptr);

private:
    double height;
};

#endif // CYLINDER_H
