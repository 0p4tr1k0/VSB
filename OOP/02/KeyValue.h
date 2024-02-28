#include <iostream>
#include <string>

class KeyValue {
    private:
        int key;
        double value;
        KeyValue *next;

    public:
        KeyValue(int k, double v);
        ~KeyValue();
        int GetKey();
        double GetValue();
        KeyValue* GetNext();
        KeyValue* CreateNext(int k, double v);
};

KeyValue::KeyValue(int k, double v){
    this->key = k;
    this->value = v;
    this->next = nullptr;
}

KeyValue::~KeyValue(){
    if (this->next != nullptr){
        delete this->next;
        this->next = nullptr;
    }
    
}

KeyValue* KeyValue::GetNext(){
    return this->next;
}

KeyValue* KeyValue::CreateNext(int k, double v){
    this->next = new KeyValue(k, v);
    return this->next;
}

inline int KeyValue::GetKey()
{
    return this->key;
}

inline double KeyValue::GetValue()
{
    return this->value;
}
