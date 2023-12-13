#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int delka_retezce(const char* retezec) {
    int delka = 0;

    while (*retezec != '\0') {
        delka = delka + 1;
        retezec = retezec + 1;  
    };
    return delka;
}

int main(){
    int cislo;
    char znaky[&znaky];

    printf("capslockify "%c"\n", &znaky);
    scanf("%c", &znaky);
    printf("Zadejte pocet slov: \n");
    scanf("%d", &cislo);

    if(cislo < 1 && cislo >10){
        printf("sptany pocet slov");
    }

    for (unsigned char l = 0; l < UCHAR_MAX; l++) {
        unsigned char u = toupper(l);
        if (u != l) printf("%c%c ", l, u);
    }
    printf("\n\n");
    printf("Parsing the input string '%s'\n", input);
    char *token = strtok(input, " ");
    while(token) {
        puts(token);
        token = strtok(NULL, " ");
    }
return 0;
}
