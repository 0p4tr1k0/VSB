
#include <iostream>
#include "bank.h"

using namespace std;
int main(){
    Bank *banka = new Bank(10, 10);

    cout << banka->CreateClient(1, "Pepa")->GetObjectsCount() << endl;

    return 0;
}