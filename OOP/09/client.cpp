#include "client.h"

int Client::objectsCount = 0;

Client::Client(int c, string n){
    this->code = c;
    this->name = n;
    Client::objectsCount += 1;
}

int Client::GetCode(){
    return this->code;
}

string Client::GetName(){
    return this->name;
}

Client::~Client(){
    Client::objectsCount -= 1;
}

int Client::GetObjectCount(){
    return Client::objectsCount;
}