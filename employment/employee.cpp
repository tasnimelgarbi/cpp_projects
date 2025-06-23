#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee()
{
    name="t";
}
Employee::Employee(string n)
{
    name=n;
}
Employee::Employee(const Employee&emp)
{
    name=emp.name;
}
void Employee::setname(string n)
{
    name = n;
}
string Employee::getname()const
{
    return name;
}
Employee::~Employee()
{
    //dtor
}
void Employee::printemployee()
{
    cout<<"the name is: "<<name<<endl;
}
