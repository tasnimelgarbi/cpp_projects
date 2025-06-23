#include "rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle()
{
    width = 0.0;
    length = 0.0;
}

Rectangle::Rectangle(double w, double l)
{
    width = w;
    length = l;
}

Rectangle::Rectangle(const Rectangle& rec)
{
    width = rec.width;
    length = rec.length;
}

void Rectangle::setdata(double w, double l)
{
    width = w;
    length = l;
}

double Rectangle::getwidth() const
{
    return width;
}

double Rectangle::getlength() const
{
    return length;
}

Rectangle::~Rectangle() {}

void display(const Rectangle& ptr)
{
    cout << "the width= " << ptr.getwidth() << endl;
    cout << "the length= " << ptr.getlength() << endl;
}
