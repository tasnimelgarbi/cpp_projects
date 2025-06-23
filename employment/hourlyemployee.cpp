#include "hourlyemployee.h"
#include <iostream>
using namespace std;

Hourlyemployee::Hourlyemployee()
{
    hourlywage=0;
    hoursworked=0;
}
Hourlyemployee::Hourlyemployee(double wa,double wo)
{
    hourlywage=wa;
    hoursworked=wo;
}
Hourlyemployee::Hourlyemployee(const Hourlyemployee&ho)
{
    hourlywage=ho.hourlywage;
    hoursworked=ho.hoursworked;
}
void Hourlyemployee::sethourly(double wa,double wo)
{
    hourlywage=wa;
    hoursworked=wo;
}
double Hourlyemployee::getwage()const
{
    return hourlywage;
}
double Hourlyemployee::getworked()const
{
    return hoursworked;
}
Hourlyemployee::~Hourlyemployee()
{
    //dtor
}
void printhourly(const Hourlyemployee&ptr){
cout<<"hourly_wage= "<<ptr.getwage()<<endl;
cout<<"hourly_worked= "<<ptr.getworked()<<endl;
}
