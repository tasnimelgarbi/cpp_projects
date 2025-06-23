#ifndef MANAGER_H
#define MANAGER_H
#include "employee.h"
#include"salariedemployee.h"

class Manager : public Salariedemployee
{
public:
    Manager();
    Manager(double,double);
    Manager(const Manager&ma);
    void setbonus(double);
   double getbonus()const;
    ~Manager();
    void printmanager();
private:
    double bonus;
};

#endif // MANAGER_H
