#include <iostream>
#include <string>
#include "employee.h"
#include "hourlyemployee.h"
#include "salariedemployee.h"
#include "manager.h"
using namespace std;

int main()
{
    string ne;
    cout<<"enter the name of employee: ";
    cin>>ne;
    Employee a;
    a.setname(ne);
    a.printemployee();
    cout<<"========================================"<<endl;

    string nh;
    double wa,wo;
    cout<<"enter the name of hourly_employee: ";
    cin>>nh;
    cout<<"enter the hourly_wage: ";
    cin>>wa;
    cout<<"enter the hourly_worked: ";
    cin>>wo;
    Hourlyemployee b;
    b.setname(nh);
    b.printemployee();
    b.sethourly(wa,wo);
    printhourly(b);
    cout<<"========================================"<<endl;

    string ns;
    double sal;
    cout<<"enter the name of salaried_employee: ";
    cin>>ns;
    cout<<"enter the salary of salaried_employee: ";
    cin>>sal;
    Salariedemployee c;
    c.setname(ns);
    c.printemployee();
    c.setsalary(sal);
    printsalaried(c);
    cout<<"========================================"<<endl;

    string nm;
    double s,bo;
    cout<<"enter the name of manager: ";
    cin>>nm;
    cout<<"enter the salary of manager: ";
    cin>>s;
    cout<<"enter the bonus: ";
    cin>>bo;
    Manager d;
    d.setname(nm);
    d.printemployee();
    d.setsalary(s);
    printsalaried(d);
    d.setbonus(bo);
    d.printmanager();
    cout<<"========================================"<<endl;

    return 0;
}
