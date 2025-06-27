#include "Surah.h"
#include <iostream>
#include <iomanip>
Surah::Surah(string n  , string t, string p) : name(n), type(t), path(p) {}

Surah::~Surah() {}

string Surah::getName() const
{
    return name;
}

string Surah::getType() const
{
    return type;
}

string Surah::getPath() const
{
    return path;
}

void Surah::inputSurah()
{
    cout <<endl<< setw (67) << "Enter Surah Name: ";
    cin >> name;
    cout <<endl<< setw (67)<< "Enter Surah Type: ";
    cin >> type;
    cin.ignore();
    cout <<endl<< setw (67) <<"Enter Surah Path: ";
    getline(cin, path);
}


ostream& operator<<(ostream& os, const Surah& surah)
{
    os << "Name: " << surah.name << ", Type: " << surah.type << ", Path: " << surah.path;
    return os;
}
