#pragma once
#include <string>
#include "client.h"

using namespace std;

class Account
{
private:
    int number;
    double balance;
    double interestRate;

    Client *owner;

public:
    Account (int n, Client *c);
    Account (int n, Client *c, double ir);
    Account (int n, Client *c, Client *p);
    Account (int n, Client *c, Client *p, double ir);

    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client *GetOwner();
    bool Canwithdraw(double a);

    void Deposit (double a);
    bool Withdraw(double a);
    void AddInterest();
};