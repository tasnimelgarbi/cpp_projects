#include "Elsheikh.h"

Elsheikh::Elsheikh(const string& name) : name(name) {}

Elsheikh::~Elsheikh() {
    suar.clear();
}

void Elsheikh::addSurah(Surah surah ) {
    Surah newSurah(surah);
    suar.append(newSurah);
}

void Elsheikh::printSheikh() const {
    cout <<endl<< setw (59)<< "Elsheikh: " << name << endl;
    suar.Display();
}

void Elsheikh::deleteSurahByName(const string& surahName) {
    if (suar.isEmpty()) {
        cout <<endl<< setw (57)<< "No Surahs available to delete." << endl;
        return;
    }
    DoublyLinkedList<Surah>::Node* current = suar.getFirst();
   do
   {
        if (current->item.getName() == surahName) {
            suar.Delete(current->item);
            cout <<endl<< setw (57)<< "Surah \"" << surahName << "\" deleted successfully." << endl;
            return;
        }
        current = current->next;
   }while (current != suar.getFirst()) ;


    cout <<endl<< setw (57)<< "Surah \"" << surahName << "\" not found." << endl;
}

string Elsheikh::getName ()
{
    return name ;
}
 bool Elsheikh::operator == (const Elsheikh & other) const
 {
     return Elsheikh::name  == other.name ;
 }

DoublyLinkedList<Surah>& Elsheikh::getSuar() {
        return Elsheikh::suar;
}

