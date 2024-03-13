#include <stdint.h>
#include <stdio.h>
#include <math.h>

//01
void mocniny( long *tp_pole, int t_N, int t_X );

//03
void convert_char(char *slovo, unsigned char volba){
    printf("%s", slovo);
}

/*int je_prvocislo(int cislo){
    if(cislo < 2){
        return 0;
    }
    for (int i = 2; i <= sqrt(cislo); ++i){
        if(cislo % i == 0){
            return 0;
        }
    }
    return 1;
}

void bez_prvocisel( int *tp_pole, int t_N ){
    for (int i = 0; i < t_N; ++i){
        if(!je_prvocislo(tp_pole[i])){
            tp_pole[i] = 0;
        }
    }
    
}*/

int main() {
    /*int N = 5;
    int X = 2;
    long pole[N];

    for (int i = 0; i < N; i++)
    {
        printf("%ld\n", pole[i]);
    }*/
    
    //printf("%d\n", sizeof(long));

    /*int pole[] = {2,7,12,5,16,11,23};
    int delka_pole = sizeof(pole) / sizeof(pole[0]);


    bez_prvocisel(pole, delka_pole);

    for (int i = 0; i < delka_pole; ++i){
        printf("%d ", pole[i]);
    }*/

    //convert_char(slovo);
    return 0;
}