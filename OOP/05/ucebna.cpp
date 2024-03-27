#include "ucebna.h"

ucebna::ucebna(string nazev, string zkratka){
    this->nazev = nazev;
    this->zkratka = zkratka;
}

string ucebna::getName(){
    return this->nazev;
}

string ucebna::getShortcut(){
    return this->zkratka;
}
