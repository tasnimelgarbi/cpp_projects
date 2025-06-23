#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include "employee.h"

class Hourlyemployee:public Employee
{
public:
    Hourlyemployee();
    Hourlyemployee(double,double);
    Hourlyemployee(const Hourlyemployee&ho);
    void sethourly(double,double);
    double getwage()const;
    double getworked()const;
    ~Hourlyemployee();
    friend void printhourly(const Hourlyemployee&ptr);
private:
    double hourlywage,hoursworked;
};

#endif // HOURLYEMPLOYEE_H
