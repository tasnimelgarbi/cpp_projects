#include "shape.h"
#include <iostream>
#include <string>
using namespace std;

Shape::Shape()
{
    color="jk";
}
Shape::Shape(string c)
{
    color=c;
}
Shape::Shape(const Shape&sh)
{
    color=sh.color;
}

Shape::~Shape()
{
}
void Shape::setcolor(string c)
{
    color=c;
}
string Shape::getcolor()
{
    return color;
}
void Shape::print(){
    cout<<"The color is: "<<color<<endl;
}
