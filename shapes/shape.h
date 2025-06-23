#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using namespace std;

class Shape
{
public:
    Shape();
    Shape(string);
    Shape(const Shape&sh);
    void setcolor(string);
    string getcolor();
    void print();
    ~Shape();

protected:
    string color;
};

#endif // SHAPE_H
