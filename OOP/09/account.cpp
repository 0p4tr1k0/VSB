#include "account.h"

int Account::objectsCount = 0;

Account::Account(int n, Client *o){
    this->number = n;
    this->owner = o;
    Account::objectsCount += 1;
    this->balance = 0;
    this->interestRate = 0;
}

Account::Account(int n, Client *o, double ir){
    this->number = n;
    this->owner = o;
    this->interestRate = ir;
    Account::objectsCount += 1;
    this->balance = 0;
    this->interestRate = ir;
}

Account::~Account(){
    Account::objectsCount -= 1;
}

int Account::GetNumber(){
    return this->number;
}

double Account::GetBalance(){
    return this->balance;
}

double Account::GetInterestRate(){
    return this->interestRate;
}

Client *Account::GetOwner(){
    return this->owner;
}

bool Account::CanWithdraw(double a){
    return (this->balance >= a);
}

void Account::Deposit(double a){
    this->balance += a;
}

bool Account::Withdraw(double a){
    bool success = false;
    if (this->CanWithdraw(a))
    {
        this->balance -= a;
        success = true;
    }
    return success;
}

void Account::AddInterest(){
    
}

int Account::GetObjectCount(){
    return Account::objectsCount;
}

PartnerAccount::PartnerAccount(int n, Client *o, Client *p) : Account(n, o){
    this->partner = p;
}

PartnerAccount::PartnerAccount(int n, Client *o, Client *p, double ir) :  Account(n, o, ir){
    this->partner = p;
}

Client *PartnerAccount::GetPartner(){
    return PartnerAccount::partner;
}

CreditAccount::CreditAccount(int n, Client *o, double c) : Account(n, o){
    this->credit = c;
}

CreditAccount::CreditAccount(int n, Client *o, double ir, double c) : Account(n, o, ir){
    this->credit = c;
}

bool CreditAccount::CanWithdraw(double a){
    return (this->GetBalance() + this->credit >= a);
}

bool CreditAccount::Withdraw(double a){
    bool success = false;
    if (this->CanWithdraw(a))
    {
        this->balance -= a;
        success = true;
    }
    return success;
}
