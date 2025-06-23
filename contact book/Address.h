#ifndef ADDRESS_H_INCLUDED
#define ADDRESS_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Address
{

private :

    size_t Street_Num ;
    string Street_Name ;
    string Town ;
    string State ;

public :


    Address(size_t SN = 0,string SName = "*****",string T = "****",string ST = "*****" )
    {
        Street_Num = SN ;
        Street_Name = SName ;
        Town = T ;
        State = ST ;
    }


    void inputAddress()
    {
        cout << "\t\t\t\t\t\t ::Enter Addres details::";

        cout << endl << "\t\t\t\t\t\t Enter Town: ";
        cin >> Town ;


        cout  << "\t\t\t\t\t\t Enter State: ";
        cin >> State;


        cout  << "\t\t\t\t\t\t Enter Street Name: ";
        cin >> Street_Name;


        cout  << "\t\t\t\t\t\t Enter Street Number: ";
        cin >> Street_Num;


        cout<<endl<<endl ;
    }


    void set_Street_num (size_t SN)
    {
        Street_Num = SN ;
    }


    void set_Street_Name (std :: string SName)
    {
        Street_Name = SName ;
    }


    void set_Town (std :: string T)
    {
        Town = T ;
    }


    void set_State (std :: string ST)
    {
        State = ST ;
    }

    size_t get_Street_Num ()
    {
        return Street_Num ;
    }
    string get_Town ()
    {
        return Town ;
    }
    string get_Street_Name ()
    {
        return Street_Name ;
    }
    string get_State ()
    {
        return State ;
    }
    string get_All_Address ()
    {
     string all_address = to_string (Street_Num) + " " + Street_Name + " " + Town + " " + State ;

     return all_address ;
    }
    void Display()
    {
        cout << Street_Num
                  <<"," << Street_Name
                  << ","<< State
                  <<","<< Town <<"\t";
    }


};

#endif // ADDRESS_H_INCLUDED


