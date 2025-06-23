#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
public:

    Rectangle();
    Rectangle(double, double);
    Rectangle(const Rectangle& rec);
    void setdata(double, double);
    double getlength()const;
    double getwidth()const;
    ~Rectangle();
    friend void display(const Rectangle& ptr);

private:
    double width, length;
};

#endif // RECTANGLE_H
