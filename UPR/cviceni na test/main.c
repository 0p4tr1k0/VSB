#include <stdio.h>
#include <stdlib.h>

struct Student {
    char jmeno[50];
    int cislo;
    int body;
};

//zpracovani prikazove radky
void zpracujArgumenty(int argc, char *argv[], char *vstupniSoubor, char *vystupniSoubor){
    for (int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-i") == 0){
            i++;
            strcpy(vstupniSoubor, argv[i]);
        }else if(strcmp(argv[i], "-o") == 0){
            i++;
            strcpy(vystupniSoubor, argv[i]);
        }
    }
    
    /*if(argc >= 3){
        if(strcmp(argv[1], "-i")){
            vstupniSoubor = argv[2];
        }
        if(strcmp(argv[3], "-o")){
            vystupniSoubor = argv[4];
        }
    }else{
        printf("nebyly zadany parametry");
    }*/
}


void nactiStudenty(FILE *soubor, struct student** studenti, int *pocetStudentu){
    char buffer[100];
    *studenti = (struct Student *)malloc(sizeof(struct Student));
    *pocetStudentu = 0;

    //načítání informací o studentech
    while (fgets(buffer, sizeof(buffer), soubor) != NULL){
        //kontrola konce souboru
        if(buffer[0] == '\n' || buffer[0] == '\r'){
            break;
        }
        //zpracování dat pomocí cyklu
        struct Student novyStudent;
        char *token = strtok(buffer, " ");

        //zpracování tří prvků v řádku
        for(int i = 0; i < 3 && token != NULL; i++){
            switch (i) {
                case 0:
                    strcpy(novyStudent.jmeno, token);
                    break;
                case 1:
                    novyStudent.cislo = atoi(token);
                    break;
                case 2:
                    novyStudent.body = atoi(token);
                    break;
            }
            token = strtok(NULL, " ");
        }
        //Zvětšení pole studentů pro další záznam
        *studenti = realloc(*studenti, (*pocetStudentu + 1) * sizeof(struct Studenti));

        //Uložení nového studenta
        (*studenti)[*pocetStudentu] = novyStudent;
        (*pocetStudentu)++;
    }
}

void zobrazVsechnyStudenty(struct student *studenti, int pocetStudentu){

}
void zpracujOperace(struct student* studenti, int pocetStudentu){

}

int main(int argc, char* argv[]){

}