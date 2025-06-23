#include "manager.h"
#include <iostream>
using namespace std;

Manager::Manager()
{
    bonus = 0;
}

Manager::Manager(double s, double b)
{
    salary = s;
    bonus = b;
}

Manager::Manager(const Manager& ma)
{
    bonus = ma.bonus;
}

void Manager::setbonus(double b)
{
    bonus = b;
}

double Manager::getbonus() const
{
    return bonus;
}

void Manager::printmanager()
{
    cout << "the bonus is: " << getbonus() << endl;
}

Manager::~Manager()
{
    //dtor
}
