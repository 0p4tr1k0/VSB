#include <stdio.h>


int mocniny(int cislo){
    return cislo*cislo;
}


int main(){
    int x = 0;
    int y = 0;

    printf("Zadejte dve kladna cisla: ");
    scanf("%d %d", &x, &y);

    if(x <= 0 || y <= 0){
        printf("Cisla musi byt kladne a vetsi nez 0\n");
        return 0;
    }else{
    printf("Uzavreny interval [%d,%d]\n", x, y);
    }


    for (int i = x; i < y+1; i++)
    {
        printf("%d ", mocniny(i));
    }
    printf("\n");
    

    return 0;
}