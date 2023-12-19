#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char jmeno[100];
    char mesto[100];
    int zlobivost;
    int pocetDarku;
}DITE;

void nacteniDoStruktury(DITE *poleDeti, int pocetDeti){
    char buffer[100];
    char *pch;
    int pocet = 0;

    for (int i = 0; i < pocetDeti; i++)
    {
        fgets(buffer,sizeof(buffer),stdin);
        pch = strtok(buffer, ",");
        while (pch != NULL)
        {
            switch (pocet)
            {
            case 0:
                strcpy(poleDeti[i].jmeno, pch);
                break;
            case 1:
                strcpy(poleDeti[i].mesto, pch);
                break;
            case 2:
                poleDeti[i].zlobivost = atoi(pch);
                break;
            case 3:
                poleDeti[i].pocetDarku = atoi(pch);
                break;
            }
            pocet++;
            pch = strtok(NULL, ",");
            //printf("mesto: %s\n", poleDeti[i].mesto);
        }
        pocet = 0;
    }
    

}



int main(int argc, char const *argv[])
{
    int pocetDeti = 0;
    int pocetDotazu = 0;

    if(argc = 3){
        pocetDeti = atoi(argv[1]);
        pocetDotazu = atoi(argv[2]);
    }else{
        printf("nebyly zadany parametry\n");
    }
    DITE *poleDeti = (DITE*)malloc(pocetDeti * sizeof(DITE));
    //DITE poleDeti[200];
    nacteniDoStruktury(poleDeti, pocetDeti);

    char buffer[100] = {};
    int found = 0;

    for (int i = 0; i < pocetDotazu; i++)
    {   
        char znak[2];
        fgets(buffer, sizeof(buffer), stdin);
        strtok(buffer, ",");
        strcpy(znak,strtok(NULL, ","));
        printf("pch: %s", znak);

        for (int i = 0; i < pocetDeti; i++)
        {
        if(strstr(poleDeti[i].jmeno, znak) != NULL){
            found++;
            printf("%s,%d\n", poleDeti[i].jmeno, poleDeti[i].zlobivost);
            break;
            }
        }
        if(found == 0){
            printf("<not-found>");
        }
    }
    




    free(poleDeti);
    return 0;
}
