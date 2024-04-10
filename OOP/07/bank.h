#pragma once
#include <string>
#include "client.h"
#include "account.h"

using namespace std;

class Bank
{
private:
    Client** clients;
    int clientsCount;

    Account** accounts;
    int accountsCount;

public:
    Bank(int c, int a);
    ~Bank();
    
    Client* GetClient(int c);
    Account* GetAccount (int n);
    
    Client* CreateClient(int c, string n);
    Account* CreateAccount(int n, Client *c);
    Account* CreateAccount(int n, Client *c, double ir);
    Account* CreateAccount(int n, Client *c, Client *p);
    Account* CreateAccount(int n, Client *c, Client *p, double ir);
    
    void AddInterest();
};
