#pragma once
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;


class Client
{
private:
    int code;
    string name;

public:
    Client(int c, string n);

    int GetCode();
    string GetName();
};

class Account
{
private:
    int number;
    double balance;
    double interestRate;

    Client *owner;
    Client *partner;

public:
    Account (int n, Client *c);
    Account (int n, Client *c, double ir);
    Account (int n, Client *c, Client *p);
    Account (int n, Client *c, Client *p, double ir);

    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client *GetOwner();
    Client *GetPartner();
    bool Canwithdraw(double a);

    void Deposit (double a);
    bool Withdraw(double a);
    void AddInterest();
};

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



