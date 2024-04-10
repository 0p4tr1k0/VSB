#include "account.h"



//Account
Account::Account(int n, Client *c){
    this->number = n;
    this->owner = c;
}

Account::Account(int n, Client *c, double ir){
    this->number = n;
    this->owner = c;
    this->interestRate= ir;
}

int Account::GetNumber()
{
    return this->number;
}

double Account::GetBalance()
{
    return this->balance;
}

double Account::GetInterestRate()
{
    return this->interestRate;
}

Client *Account::GetOwner()
{
    return this->owner;
}

bool Account::CanWithdraw(double a)
{
    if(a > 0){
        return true;
    }else{
        return false;
    }    
}

Client *PartnerAccount::GetPartner()
{
    return PartnerAccount::partner;
}


//Parnter Account
PartnerAccount::PartnerAccount(int n, Client *o, Client *p) : Account(n, o){
    this->partner = p;
}

PartnerAccount::PartnerAccount(int n, Client *o, Client *p, double ir) : Account(n, o, ir){
    this->partner = p;
}

