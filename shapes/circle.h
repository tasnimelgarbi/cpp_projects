#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
// Include any necessary headers for Shape class if it exists

class Circle : public Shape
{
public:
    Circle();
    Circle(double);
    Circle(const Circle&ptr);
    void setradius(double r);
    double getradius() const; // Assuming this function is const
    double getarea() const; // Assuming this function is const
    ~Circle();
    friend void printCircle(const Circle& ci);
protected:
    double radius;
};

#endif // CIRCLE_H
