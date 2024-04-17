#include <iostream>
#include "bank.h"

using namespace std;

int main(){
    Client *o = new Client(0, "Smith");

    CreditAccount *ca = new CreditAccount(1, o, 1000);
    cout<<ca->CanWithdraw(1000) << endl;

    Account *a = ca;
    cout << a->CanWithdraw(1000) << endl;

    cout << ca->Withdraw(1000) << endl;

    cout << ca->GetBalance() << endl;

    a = nullptr;
    delete ca;

    return 0;
}
