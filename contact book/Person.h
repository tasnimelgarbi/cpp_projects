#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <iostream>
#include <string>
#include <algorithm>
#include "Address.h"
#include <iomanip>
#include <algorithm>
using namespace std;
class Person
{
private :
    string First_Name ;
    string Last_Name ;
    string Class ;
    size_t Capacity_of_Nums ;
    string *ptr_Nums ;
    size_t Capacity_of_Mails ;
    string *ptr_Mails ;
    Address address ;
    static int num;
public :


    Person (string FN = "*****",string LN = "*****", string C = "*****",size_t Cap_of_Nums = 2,size_t Cap_of_Mails = 2,int n = 0, Address Add = Address())
    {
        First_Name = FN ;
        Last_Name = LN ;
        Class = C ;
        Capacity_of_Nums = Cap_of_Nums ;
        ptr_Nums = new string [Capacity_of_Nums];
        Capacity_of_Mails = Cap_of_Mails;
        ptr_Mails = new string [Capacity_of_Mails];
        num=n;
        address = Add ;
    }

    ~Person()
    {
        delete[] ptr_Nums;
        delete[] ptr_Mails;
    }


    Person(const Person& p)
    {
        First_Name=p.First_Name;
        Last_Name=p.Last_Name;
        Class = p.Class ;
        Capacity_of_Nums=p.Capacity_of_Nums;
        Capacity_of_Mails=p.Capacity_of_Mails;
        address=p.address;
        num=p.num;
        ptr_Nums = new string[Capacity_of_Nums];
        copy(p.ptr_Nums, p.ptr_Nums + Capacity_of_Nums, ptr_Nums);

        ptr_Mails = new string[Capacity_of_Mails];
        copy(p.ptr_Mails, p.ptr_Mails + Capacity_of_Mails, ptr_Mails);
    }


    Person& operator=(const Person& p)
    {
        if (this != &p)
        {

            delete[] ptr_Nums;
            delete[] ptr_Mails;

            First_Name = p.First_Name;
            Last_Name = p.Last_Name;
            Class = p.Class ;
            Capacity_of_Nums = p.Capacity_of_Nums;
            Capacity_of_Mails = p.Capacity_of_Mails;
            address = p.address;
            num=p.num;

            ptr_Nums = new string[Capacity_of_Nums];
            copy(p.ptr_Nums, p.ptr_Nums + Capacity_of_Nums, ptr_Nums);

            ptr_Mails = new string[Capacity_of_Mails];
            copy(p.ptr_Mails, p.ptr_Mails + Capacity_of_Mails, ptr_Mails);
        }
        return *this;
    }


     static bool GetFav()
    {

        if(num == 1)
        {
            return true ;
        }
        else
        {
            return false ;
        }
    }


    void inputPerson ()
    {

        cout << endl << "\t\t\t\t\t\t\ Enter First Name: ";
        cin >> First_Name ;

        cout  << "\t\t\t\t\t\t\ Enter Last Name: ";
        cin >> Last_Name ;
        cout<<"\t\t\t\t\t\t\ Set as Fav : press 1 (Fav) or 0 (Not) ) " ;
        cin>>num;

        cout  << "\t\t\t\t\t\t\ Enter Class (Friend,Work,Family,Other): ";
        cin >> Class ;

        cout  << "\t\t\t\t\t\t\ How many numbers: ";
        cin >> Capacity_of_Nums;

        delete[] ptr_Nums;
        ptr_Nums = new string[Capacity_of_Nums];

        for (int i = 0 ; i<Capacity_of_Nums ; i++)
        {
            cout  << "\t\t\t\t\t\t\ Phone #"<<i+1<<": ";
            cin >> ptr_Nums[i] ;
        }
        cout  << "\t\t\t\t\t\t\ How many mails: ";
        cin >> Capacity_of_Mails;

        delete[] ptr_Mails;
        ptr_Mails = new string[Capacity_of_Mails];


        for (int i = 0 ; i<Capacity_of_Mails ; i++)
        {
            cout  << "\t\t\t\t\t\t\ Mail #"<<i+1<<": ";
            cin >> ptr_Mails[i] ;
        }
        address.inputAddress();
        cout<<endl;
    }
    string get_First_Name ()
    {
        return First_Name ;
    }
    string get_Last_Name ()
    {
        return Last_Name ;
    }
    string get_Classifacation ()
    {
        return Class;
    }
    string get_phone_Numbers ()
    {
        string all_Numbers ;
        for (int i = 0 ; i<Capacity_of_Nums ; i++)
        {
            all_Numbers += ptr_Nums[i];
            all_Numbers += "  " ;
        }
        return all_Numbers;
    }
    string get_Mails()
    {
        string all_Mails ;
        for (int i = 0 ; i<Capacity_of_Nums ; i++)
        {
            all_Mails += ptr_Mails[i];
            all_Mails  += "  " ;
        }
        return all_Mails;
    }


    void set_First_Name (string FN)
    {
        First_Name = FN ;
    }


    void set_Last_Name (string LN)
    {

        Last_Name = LN ;

    }


    void set_Class (string C)
    {

        Class = C ;
    }


    void display()
    {
        cout << setw(10) << " Name: " << setw(15) << First_Name
             << setw(15) << Last_Name
             << setw(25) << "Classification: " << Class << "\n";
        cout << "\t\t\t\t\t\t\ __________________________________________________________________________________________\n";
    }

    string get_Address()
    {
        return address.get_All_Address();
    }

    void displayadress()
    {
        address.Display();
    }
    bool operator==(const Person& P ) const
    {
        return (First_Name == P.First_Name &&Last_Name == P.Last_Name &&Class == P.Class);
    }

};
int Person::num=0;

#endif // PERSON_H_INCLUDED
