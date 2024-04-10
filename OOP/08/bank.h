#pragma once
#include "account.h"
#include "client.h"

class Bank{
private:
    Client * * clients;
    int clientsCount;

    Account** accounts;
    int accountsCount;
public:
    Bank(int c, int a);
    ~Bank();

    Client* GetClient(int c);
    Account* GetAccount(int n);

    Client* CreateClient(int c, string n);
    Account* CreateAccount(int n, Client *o);
    Account* CreateAccount(int n, Client *o, double ir);
    PartnerAccount* CreateAccount(int n, Client *o, Client *p);
    PartnerAccount* CreateAccount(int n, Client *o, Client *p, double ir);

    void addInterest();

};