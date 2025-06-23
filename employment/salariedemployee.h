#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H
#include "employee.h"

class Salariedemployee:public Employee
{
public:
    Salariedemployee();
    Salariedemployee(double);
    Salariedemployee(const Salariedemployee&sal);
    void setsalary(double);
    double getsalary()const;
    ~Salariedemployee();
    friend void printsalaried(const Salariedemployee&ptr);

protected:
    double salary;
};

#endif // SALARIEDEMPLOYEE_H
