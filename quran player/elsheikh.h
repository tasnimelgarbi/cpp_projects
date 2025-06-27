#ifndef ELSHEIKH_H
#define ELSHEIKH_H

#include "DoublyLinkedList.h"
#include "Surah.h"
#include <string>
using namespace std;

class Elsheikh
{
private:
    string name;
    DoublyLinkedList<Surah> suar;

public:
    Elsheikh(const string& name);
    ~Elsheikh();

    string getName () ;
    void addSurah(Surah surah );
    void deleteSurahByName(const string& surahName);
    void printSheikh() const;
    bool operator == (const Elsheikh & other) const ;
    DoublyLinkedList<Surah>& getSuar() ;
};

#endif // ELSHEIKH_H
