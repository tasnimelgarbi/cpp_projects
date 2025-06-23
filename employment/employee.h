#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
public:
    Employee();
    Employee(string);
    Employee(const Employee&emp);
    void setname(string);
    string getname()const;
    ~Employee();
    void printemployee();
    protected:
        string name;
};

#endif // EMPLOYEE_H
