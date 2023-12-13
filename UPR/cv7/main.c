#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct osoba{
char jmeno[30];
int vek;
}tOsoba;

int main(){
    int pocetOsob;
    printf("Zadej pocet osob: ");
    scanf("%d", &pocetOsob);

    tOsoba *poleOsob = (tOsoba *)malloc(pocetOsob * sizeof(tOsoba));

    if ((poleOsob == NULL)){
        printf("zadna nula blbecku");
        return 1;
    }

    for(int i = 0; i < pocetOsob; i++){
        printf("zadej %d. osobu:\n", i+1);
        printf("Jmeno:");
        scanf("%s", poleOsob[i].jmeno);
        printf("Vek: ");
        scanf("%d", &poleOsob[i].vek);
    }

    int nejstarsi = 0;
    for (int i = 1; i < pocetOsob; i++){
        if(poleOsob[i].vek > poleOsob[nejstarsi].vek){
            nejstarsi = i;
        }
    }

    printf("Nejstarsi je %s s vekem %d let.", poleOsob[nejstarsi].jmeno, poleOsob[nejstarsi].vek);

    free(poleOsob);
    return 0;
}