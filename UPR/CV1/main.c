#include <stdio.h>


int main() {
    int cislo;
    printf("Zadej cislo:\n");
    scanf("%d", &cislo);
    if(cislo < 5){
        printf("je mensi\n");
    }else if(cislo == 5){
        printf("je stejne\n");
    }else{
        printf("je mensi\n");
    }
    return 0;
}