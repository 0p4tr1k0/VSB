#pragma once
#include "client.h"

class Account{
private:
    int number;
    double interestRate;
    static int objectsCount;

    Client *owner;
protected:
    double balance;

public:
    Account(int n, Client *o);
    Account(int n, Client *o, double ir);
    
    ~Account();

    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client *GetOwner();

    bool CanWithdraw(double a);

    void Deposit(double a);
    bool Withdraw(double a);
    void AddInterest();
    static int GetObjectCount();
};

class PartnerAccount : public Account{
private:
    Client *partner;
public:
    PartnerAccount(int n, Client *o, Client *p);
    PartnerAccount(int n, Client *o, Client *p, double ir);

    Client *GetPartner();
};

class CreditAccount : public Account{
private:
    double credit;
public:
    CreditAccount(int n, Client *o, double c);
    CreditAccount(int n, Client *o, double ir, double c);
    
    bool CanWithdraw(double a);
    bool Withdraw(double a);
};