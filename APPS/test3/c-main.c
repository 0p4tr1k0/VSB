#include <stdio.h>
#include <stdint.h>

// Deklarace funkce v C
//01
long nejmensi_56bit(long *tp_array, int t_N);
//02
void long2hexstr(long t_num, char *tp_str);
//03
int pismena(char *tp_str);
//04
int pocet_slov(char *tp_str);


int main() {
    // 01
    long array[] = {0x0123456789abcdef, 0x0000000000000000, 0x9876543210fedcba};
    int N = sizeof(array) / sizeof(array[0]);
    long result = nejmensi_56bit(array, N);
    // 02
    long num = 0x12345678;
    char str[9];  // 8 hex znaků + '\0'
    long2hexstr(num, str);
    //03
    char str[] = "AaBbCc";
    int result = pismena(str);
    //04
    char str[] = " Pomalu zacina jaro .";
    int result = pocet_slov(str);
    
    
    return 0;
}