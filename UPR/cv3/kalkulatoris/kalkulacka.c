#include <stdio.h>

int main(){
    char typFunkce;
    int a;
    int b;
    
    printf("Zvolte funkci: (+ | - | * | /) \n");
    scanf("%c", &typFunkce);

    if(typFunkce == '+'){
        printf("zvolena funkce je +\n");
    }else if(typFunkce == '-'){
        printf("Zvolena funkce je -\n");
    }else if(typFunkce == '*'){
        printf("Zvolena funkce je *\n");
    }else if(typFunkce == '/'){
        printf("Zvolena funkce je /\n");
    }
    printf("Zadej hodnotu A: \n");
    scanf("%d",&a);
    printf("Zadej hodnotu funkce B: \n");
    scanf("%d", &b);
    switch (typFunkce)
    {
    case '+':
        printf("%d + %d = %d", a, b, a+b);
        break;
    case '-':
        printf("%d + %d = %d", a, b, a-b);
        break;
    case '*':
        printf("%d + %d = %d", a, b, a*b);
        break;
    case '/':
        printf("%d + %d = %d", a, b, a/b);
        break;
    }
    return 0;
}