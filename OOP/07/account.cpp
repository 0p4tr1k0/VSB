#include "account.h"



Account::Account(int n, Client *c){
    this->number = n;
    this->owner = c;
    this->balance = 0;
    this->interestRate = 0;
}


Account::Account(int n, Client *c, double ir){
    this->number = n;
    this->owner = c;
    this->balance = 0;
    this->interestRate= ir;
}
