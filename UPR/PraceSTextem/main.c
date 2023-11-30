#include <stdio.h>
#include <ctype.h>
#include <string.h>

void normalizovatSlovo(char *slovo) {
    int obsahujeVelke = 0;

    for (int i = 0; slovo[i]; i++) {
        if (isupper(slovo[i])) {
            obsahujeVelke = 1;
            slovo[i] = tolower(slovo[i]);
        }
    }

    if (obsahujeVelke) {
        slovo[0] = toupper(slovo[0]);
    }
}

int main() {
    int n;
    char radek[51];

    printf("Zadejte pocet radku: ");
    scanf("%d", &n);
    getchar();

    for (int i = 1; i <= n; i++) {
        printf("Zadejte radek %d: ", i);
        fgets(radek, sizeof(radek), stdin);

        int delka = strlen(radek);
        while (delka > 0 && isspace(radek[delka - 1])) {
            radek[--delka] = '\0';
        }
        int zacatek = 0;
        while (zacatek < delka && isspace(radek[zacatek])) {
            zacatek++;
        }

        char *radek_bezMezer = radek + zacatek;

        int pocetMalychPismenPuvodni = 0;
        int pocetMalychPismenNormalizovanych = 0;
        int pocetVelkychPismenPuvodni = 0;
        int pocetVelkychPismenNormalizvanych = 0;
        int pocetMezerPuvodni = 0;
        int pocetMezerNormalizovany = 0;

        char normalizovany_radek[51];
        int delka_normal_radku = 0;

        for (int j = 0; j < delka; j++) {
            char původní_znak = radek[j];

            if (islower(původní_znak)) {
                pocetMalychPismenPuvodni++;
            } else if (isupper(původní_znak)) {
                pocetVelkychPismenPuvodni++;
            } else if (isspace(původní_znak)) {
                pocetMezerPuvodni++;
            }

            if (!isspace(původní_znak)) {
                normalizovany_radek[delka_normal_radku] = původní_znak;
                delka_normal_radku++;

                if (j < delka - 1 && isspace(radek[j + 1])) {
                    normalizovany_radek[delka_normal_radku] = ' ';
                    delka_normal_radku++;
                }
            }
        }

        normalizovany_radek[delka_normal_radku] = '\0';

        char *slovo = strtok(normalizovany_radek, " \t\n");
        while (slovo != NULL) {
            normalizovatSlovo(slovo);
            pocetMalychPismenNormalizovanych += strlen(slovo);
            slovo = strtok(NULL, " \t\n");
        }

        printf("Puvodni radek: %s\n", radek);
        printf("Znormalizovany radek: %s\n", normalizovany_radek);

        printf("Puvodni malych pismen: %d\n", pocetMalychPismenPuvodni);
        printf("Znormalizovanych malych pismen: %d\n", pocetMalychPismenNormalizovanych);
        printf("Puvodni velkych pismen: %d\n", pocetVelkychPismenPuvodni);
        printf("Znormalizovanych velkych pismen: %d\n", pocetVelkychPismenNormalizvanych); // Velká písmena zůstávají zachována
        printf("Puvodni mezer: %d\n", pocetMezerPuvodni);
        printf("Znormalizovanych mezer: %d\n", pocetMezerNormalizovany);

        printf("\n");
    }

    return 0;
}