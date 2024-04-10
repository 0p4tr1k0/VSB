#pragma once
#include <string>
#include "client.h"


class Account{
private:
    int number;
    double balance;
    double interestRate;

    Client *owner;
    

public:
    Account(int n, Client *o);
    Account(int n, Client *o, double ir);
    
    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client *GetOwner();
    bool CanWithdraw(double a);

    void Deposit(double a);
    bool Withdraw(double a);
    void AddInterest();
};

class PartnerAccount : public Account{
private:
    Client *partner;
public:
    PartnerAccount(int n, Client *o, Client *p);
    PartnerAccount(int n, Client *o, Client *p, double ir);

    Client *GetPartner();
};