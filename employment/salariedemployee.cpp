#include "salariedemployee.h"
#include <iostream>
using namespace std;

Salariedemployee::Salariedemployee()
{
    salary=0;
}
Salariedemployee::Salariedemployee(double s)
{
    salary = s;
}
Salariedemployee::Salariedemployee(const Salariedemployee&sal)
{
    salary=sal.salary;
}
void Salariedemployee::setsalary(double s)
{
    salary= s;
}
double Salariedemployee::getsalary()const
{
    return salary;
}
Salariedemployee::~Salariedemployee()
{
    //dtor
}
void printsalaried(const Salariedemployee&ptr)
{
    cout<<"the salary is: "<<ptr.getsalary()<<endl;
}
