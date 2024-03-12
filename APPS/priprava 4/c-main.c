#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

//01
long faktorial(int N);
//02
void nejvetsi_modulo(int *tp_pole, int t_N, int t_K);
//03
void preved_na_velka(char *tp_str);
//04
void convert_case(char *tp_str);
//05
bool je_prvocislo(long num);
//06
int soucin(char *tp_str);

int main() {
    // 01
    int num = 5;
    long result = faktorial(num);
    //02
    int array[] = {10, 15, 8, 20, 25};
    int N = sizeof(array) / sizeof(array[0]);
    int K = 4;
    nejvetsi_modulo(array, N, K);
    //03
    char str[] = "AaBbCc";
    preved_na_velka(str);   
    //04
    char str[] = "AbCdEfG";
    convert_case(str);
    //05
    long num = 17;
    bool result = je_prvocislo(num);
    //06
    char str[] = "Po56r4v dn3";
    int result = soucin(str);


    return 0;
}
