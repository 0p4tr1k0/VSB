#include <stdio.h>
#include <stdlib.h>

int zjistiPocetCisel(FILE *soubor) {
    
    fseek(soubor, 0, SEEK_END);

    int velikost = ftell(soubor);
    
    
}

int main() {
    FILE *soubor = fopen("cisla.bin", "wb");
    if (soubor == NULL) {
        printf("Nepodarilo se otevritsoubor.");
        return 1;
    }
    
    int pocetCisel = rand() % 41 + 10;
    
    return 0;
}
