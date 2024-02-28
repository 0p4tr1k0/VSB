#include "KeyValue.h"

using namespace std;




int main(){

    KeyValue *kv1 = new KeyValue(1, 1.5);
    cout << kv1->CreateNext(2, 2.5)->GetKey() << endl;

    KeyValue *kv2 = kv1->GetNext();
    cout <<  kv2->GetNext() << endl;


    delete kv1;
    //delete kv2

    cout << kv1->GetKey() << endl;
    cout << kv2->GetKey() << endl;

    getchar();
    return 0;
}