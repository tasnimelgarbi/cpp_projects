#ifndef SURAH_H
#define SURAH_H

#include <string>
using namespace std;

class Surah
{
private:
    string name;
    string type;
    string path;

public:
    Surah(string n = "*****", string t = "*****", string p = "*****");
    ~Surah();

    string getName() const;
    string getType() const;
    string getPath() const;

    void inputSurah();

    bool operator==(const Surah& other) const {
        return name == other.name && type == other.type && path == other.path;
    }

    friend ostream& operator<<(ostream& os, const Surah& surah);
};

#endif // SURAH_H
