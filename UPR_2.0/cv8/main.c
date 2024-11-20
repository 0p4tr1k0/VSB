#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(){

    int a = INT_MAX;

    FILE* file = fopen("cisla.txt", "w");

    fwrite(&a, sizeof(a), 1, file);

    
    
    fclose(file);

    file = fopen("cisla.txt", "r");
    
    

  
    fclose(file);
    /*srand(time(NULL));
    int a = rand() %36 - 15;
    
    printf("cislo: %d\n", a);
    */
    return 0;

}