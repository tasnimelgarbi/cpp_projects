#include "circle.h"
#include <iostream>
using namespace std;

Circle::Circle() {
    radius = 0;
}

Circle::Circle(double r) {
    radius = r;
}

Circle::Circle(const Circle& ptr) {
    radius = ptr.radius;
}

void Circle::setradius(double r) {
    radius = r;
}

double Circle::getarea() const {
    return 3.14 * radius * radius;
}

double Circle::getradius() const {
    return 2 * 3.14 * radius;
}

Circle::~Circle() {
    // Destructor
}

void printCircle(const Circle& ci) {
    cout << "The area of circle is: " << ci.getarea() << endl;
    cout << "The radius of circle is: " << ci.getradius() << endl;
}
