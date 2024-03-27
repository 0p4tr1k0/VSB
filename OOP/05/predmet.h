#pragma once
#include <string>
#include "ucitel.h"

using namespace std;

class predmet
{
private:
    string zkratka;
    ucitel *id;
    string nazev;
public:
    predmet(string zkratka, ucitel *id,string nazev);
    string getName();
    string getShortcut();
    string getID();
};

