#include <stdio.h>

int main(){
    char moznost;
    int stavUctu = 1000;
    int zustatek;
    int vyber;
    int vklad;
    printf("Zadejte volbu: \n");
    printf("V - Vklad hotovosti\n");
    printf("M - Vyber hotovosti\n");
    printf("Z - Zustatek hotovosti\n");
    scanf("%c", &moznost);

    if(moznost == 'V'){
        printf("Volba vkladu.\n");
        printf("Vlozte castku pro vklad: ");
        scanf("%d", &vklad);
        printf("Momentalni stav uctu: ");
    }else if(moznost == 'M'){
        printf("Volba vyberu.\n");
        printf("Zadejte castku vyberu: \n");
        scanf("%d", &vyber);
        printf("Momentalni stav uctu: ");
    }else if (moznost == 'Z'){
        printf("Vas zustatek je %d", stavUctu);
    }

    switch (moznost)
    {
    case 'V':
        printf("novy zustatek je %d.\n", stavUctu+vklad);
        break;
    case 'M':
        if (stavUctu < vyber){
            printf("Nedostatek penez na uctu\n");
        }else{
            printf("novy zustatek je %d.", stavUctu - vyber);
        }
        break;
    }
return 0;}