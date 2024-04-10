#include "bank.h"

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

void Bank::addInterest()
{
}