#pragma once
#include <string>

using namespace std;

class ucebna
{
private:
    string nazev;
    string zkratka;
public:
    ucebna(string nazev, string zkratka);
    string getName();
    string getShortcut();
    
};