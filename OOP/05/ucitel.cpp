#include "ucitel.h"


ucitel::ucitel(int id, string jm, string pri, string pre){
    this->id = id;
    this->jmeno = jm;
    this->prijmeni = pri;
    this->predmet = pre;
}

string ucitel::getName(){
    return this->jmeno;
    return this->prijmeni;
}

string ucitel::getSubject(){
    return this->predmet;
}
