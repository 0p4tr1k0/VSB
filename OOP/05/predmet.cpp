#include "predmet.h"

predmet::predmet(string zkratka, ucitel *id, string nazev){
    this->zkratka = zkratka;
    this->nazev = nazev;
    this->id = id;
}

string predmet::getName()
{
    return this->nazev = nazev;
}

string predmet::getShortcut()
{
    return this->zkratka = zkratka;
}

string predmet::getID()
{
    return this->id = id;
}
