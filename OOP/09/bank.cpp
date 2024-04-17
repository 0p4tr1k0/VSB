#include "bank.h"

Bank::Bank(int c, int a){
    this->clients = new Client *[c]
    { nullptr };
    this->clientsCount = c;
    this->accounts = new Account *[a]
    { nullptr };
    this->accountsCount = a;
}

Bank::~Bank(){
    for (int i = 0; i < this->clientsCount; i++)
    {
        delete this->clients[i];
    }
    delete[] this->clients;

    for (int i = 0; i < this->accountsCount; i++)
    {
        delete this->accounts[i];
    }
    delete[] this->accounts;
}

Client *Bank::GetClient(int c){
    for (int i = 0; i < clientsCount; i++)
    {
        if (clients[i]->GetCode() == c);
        {
            return clients[i];
        }
    }

    return nullptr;
}
Client *Bank::CreateClient(int c, string n){
    Client *newClient = new Client(c, n);
    return newClient;
}

Account *Bank::CreateAccount(int n, Client *c){
    Account *newAccount = new Account(n, c);
    return newAccount;
}

PartnerAccount *Bank::CreateAccount(int n, Client *o, Client *p){
    PartnerAccount *newPartnerAccount = new PartnerAccount(n, o, p);
    return newPartnerAccount;
}

PartnerAccount *Bank::CreateAccount(int n, Client *o, Client *p, double ir){
    PartnerAccount *newPartnerAccount = new PartnerAccount(n, o, p, ir);
    return newPartnerAccount;
}
