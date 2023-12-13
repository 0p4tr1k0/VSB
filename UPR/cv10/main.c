#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100

int main() {
    int* pole1;
    int* pole2;
    int velikost_pole;
    
    velikost_pole = 10;
    pole1 = (int*) malloc(velikost_pole * sizeof(int));
    for (int i = 0; i < velikost_pole; i++) {
        pole1[i] = rand() % (MAX_VALUE + 1);
    }
    
    FILE* soubor;
    if ((soubor = fopen("data.bin", "wb")) == NULL) {
        printf("Chyba při otevírání souboru\n");
        return 1;
    }

    fwrite(&velikost_pole, sizeof(int), 1, soubor);
    fwrite(pole1, sizeof(int), velikost_pole, soubor);
    fclose(soubor);

    soubor = fopen("data.bin", "rb");
    if (soubor == NULL) {
        printf("Chyba při otevírání souboru.");
        return 1;
    }

    fread(&velikost_pole, sizeof(int), 1, soubor);
    pole2 = (int*)malloc(velikost_pole * sizeof(int));

    fread(pole2, sizeof(int), velikost_pole, soubor);

    fclose(soubor);

    
    printf("\nHodnoty ze souboru data.bin:\n");
    for (int i = 0; i < velikost_pole; i++)
    {
        printf("%d ", pole2[i]);
    }printf("\n");
    

    free(pole1);
    free(pole2);
    
    return 0;
}