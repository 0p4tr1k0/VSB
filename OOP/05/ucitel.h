#pragma once
#include <string>
#include "ucitel.h"

using namespace std;



class ucitel{
private:
    int id;
    string jmeno;
    string prijmeni;
    string predmet;
public:
    ucitel(int id, string jm, string pri, string pre);
    string getName();
    string getSubject();
};