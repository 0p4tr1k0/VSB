#include <stdio.h>

unsigned long int faktorial(unsigned long cislo){
    
    unsigned long faktorial = 1;

    for (int i = 1; i <= cislo; i++)
    {
        faktorial = faktorial * i;
    }
    
    return faktorial;
}

int main(){
    unsigned long x = 0;
    

    printf("Zadejte kladne cislo: ");
    scanf("%ld", &x);

    if(x <= 0){
        printf("Cislo musi byt kladne a vetsi nez 0\n");
        return 0;
    }else{
    printf("Cislo: %ld \n", x);
    }

    printf("%ld", faktorial(x));
    printf("\n");
    return 0;
}