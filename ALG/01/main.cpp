#include<stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include<numeric>


using namespace std;



//ax2+bx+c=0
void quadratic_equation(float a, float b, float c){
    float discriminant = b*b - 4*a*c;
    float x1, x2;

    if(discriminant > 0){
        cout << "2 solutions\n";
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);

        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } else if(discriminant == 0){
        x1 = -b / (2*a);

        cout << "1 solution\n";
        cout << "x1 = " << x1 << std::endl;
    } else {
        cout << "No real solutions.\n";
    }
}


int calculateGCD(int e, int f){
    if(f == 0){
        return e;
    }
    return calculateGCD(f, e%f);
}

void euklid_GCD(int e, int f){
    int result = calculateGCD(e, f);
    cout << "GCD of " << e << " and " << f << " is: " << result << endl;
    
}



int main(){
float a, b, c;
    cout << "first number: ";
    cin >> a;
    cout << "second number: ";
    cin >> b;
    cout << "third number: ";
    cin >> c;

    quadratic_equation(a, b, c);

int e, f;
    cout << "first number:";
    cin >> e;
    cout << "second number: ";
    cin >> f;

    euklid_GCD(e, f);

    return 0;
}