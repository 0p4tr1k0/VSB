#include "bank.h"

Bank::Bank(int c, int a){
    this->clients = new Client *[c] {nullptr};
    this->clientsCount = c;
    this->accounts = new Account *[c] {nullptr};
    this->accountsCount = c;
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
