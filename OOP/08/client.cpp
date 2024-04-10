#include "client.h"


//Client
Client::Client(int c, string n){
    this->code = c;
    this->name = n;

}

int Client::GetCode()
{
    return this->code;
}

string Client::GetName()
{
    return this->name;
}


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

Account::Account(int n, Client *c, Client *p){
    this->number = n;
    this->owner = c;
    this->partner = p;
}

Account::Account(int n, Client *c, Client *p, double ir){
    this->number = n;
    this->owner = c;
    this->partner = p;
    this->interestRate = ir;
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

Client *Account::GetPartner()
{
    return this->partner;
}

bool Account::Canwithdraw(double a)
{
    if(a > 0){
        return true;
    }else{
        return false;
    }    
}

void Account::Deposit(double a){
    this->balance += a;
}

bool Account::Withdraw(double a){
    if (Canwithdraw(a))
    {
        this->balance -= a;
    }else{
        cout << "Na uctu neni dost penez" << endl;
    }
    return Withdraw;
}

void Account::AddInterest(){

}

          
//Bank      

Bank::Bank(int c, int a){

}

Bank::~Bank(){

}

Client *Bank::GetClient(int c)
{
    this->clients;
}

Account *Bank::GetAccount(int n)
{
    this->accounts;
}

Client *Bank::CreateClient(int c, string n)
{
    return nullptr;
}

Account *Bank::CreateAccount(int n, Client *c)
{
    return nullptr;
}

Account *Bank::CreateAccount(int n, Client *c, double ir)
{
    return nullptr;
}

Account *Bank::CreateAccount(int n, Client *c, Client *p)
{
    return nullptr;
}

Account *Bank::CreateAccount(int n, Client *c, Client *p, double ir)
{
    return nullptr;
}

void Bank::AddInterest()
{
}
