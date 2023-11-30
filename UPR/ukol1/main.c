#include <stdio.h>

int main() {
    int castka;
    int castkaminus;
    int pet_tisic = 5000;
    int dva_tisice = 2000;
    int tisic = 1000;
    int pet_set = 500;
    int dve_ste = 200;
    int sto = 100;
    char z;


    do {
        printf("Zadejte castku: ");
        scanf("%d", &castka);

        castkaminus = castka / pet_tisic;

        castka -= castkaminus * pet_tisic;


        printf("bankovka 5000: %dx\n", castkaminus);

        castkaminus = 0;

        castkaminus = castka / dva_tisice;

        castka -= castkaminus * dva_tisice;

        printf("bankovka 2000: %dx\n", castkaminus);

        castkaminus = 0;

        castkaminus = castka / tisic;

        castka -= castkaminus * tisic;

        printf("bankovka 1000: %dx\n", castkaminus);

        castkaminus = 0;

        castkaminus = castka / pet_set;

        castka -= castkaminus * pet_set;

        printf("bankovka 500: %dx\n", castkaminus);

        castkaminus = 0;

        castkaminus = castka / dve_ste;

        castka -= castkaminus * dve_ste;

        printf("bankovka 200: %dx\n", castkaminus);

        castkaminus = 0;

        castkaminus = castka / sto;

        castka -= castkaminus * sto;

        printf("bankovka 100: %dx\n", castkaminus);
        castkaminus = 0;
        printf("chcete pokracovat?: a/n \n");
        scanf(" %c", &z);
    } while (z == 'a');
    return 0;
}