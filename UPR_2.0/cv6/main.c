#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlength(char *str){
    int count =0;
    while (str(count)!= '\0')
    {
        count ++;
    }
    return count;
}


int main(){

    /*char str[] = "Tohle je testovaci retezec";
    char* str2 = "Tohle je testovaci retezec";

    char buffer[256];
    
    char znak = fgets(buffer, 256, stdin);
    
    

    printf("%s\n", buffer);*/


    int N = 4096;
    char* dyn_buffer = (char*) malloc(sizeof(char) * N);


    fgets(dyn_buffer, N, stdin);

    printf("%d", strlength(dyn_buffer));


    printf("%s", dyn_buffer);


    free(dyn_buffer);
    dyn_buffer = NULL;

    return 0;
}