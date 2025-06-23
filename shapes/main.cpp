#include <iostream>
#include <string>
#include "Shape.h"
#include "Rectangle.h"
#include "circle.h"
#include "cylinder.h"

using namespace std;

int main()
{
    string s;
    cout << "Enter the color of the shape: ";
    cin >> s;
    Shape a;
    a.setcolor(s);
    a.print();
    cout << "=======================" << endl;

    string x;
    double w, l;
    cout << "Enter the color of the rectangle: ";
    cin >> x;
    cout << "Enter the width of the rectangle: ";
    cin >> w;
    cout << "Enter the length of the rectangle: ";
    cin >> l;
    Rectangle b;
    b.setcolor(x);
    b.setdata(w, l);
    b.print();
    display(b);
    cout << "=======================" << endl;

    double r;
    string y;
    cout << "Enter the color of the circle: ";
    cin >> y;
    cout << "Enter the radius of circle: ";
    cin >> r;
    Circle c;
    c.setcolor(y);
    c.setradius(r);
    c.print();
    printCircle(c);
    cout << "=======================" << endl;

    double h,r2;
    string z;
    cout << "Enter the color of the cylinder: ";
    cin >> z;
    cout << "Enter the radius of cylinder: ";
    cin >> r2;
    cout<<"enter the height of cylinder: ";
    cin>>h;
    Cylinder d;
    d.setradius(r2);
    d.setcylinder(h);
    d.print();
    printCircle(d);
    printcylinder(d);
    cout << "=======================" << endl;

    return 0;
}
