#include <iostream>
#include "bank.h"

using namespace std;



int main(){
    Account *a;
    PartnerAccount *pa;

    Bank *b = new Bank(100, 1000);
    Client *o = b->CreateClient(0, "Smith");
    Client *p = b->CreateClient(1, "Jones");
    a = b->CreateAccount(0, o);
    pa = b->CreateAccount(1, o, p);

    cout << a->GetOwner()->GetName() << endl;
    cout << pa->GetPartner()->GetName() << endl;

    cout << b->GetClient(1)->GetName() << endl;

    //cout << b->GetClient(1)->GetPartner() << endl;

    getchar();
    return 0;

}