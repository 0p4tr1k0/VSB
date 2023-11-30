#include <stdio.h>

int main() {
    int obrazec = 0;
    int a = 0;
    int b = 0;
    int cislo = 0;


    printf("Zadejte typ obrazce: \n");
    printf("0 - plny obdelnik\n");
    printf("1 - duty obdelnik\n");
    printf("2 - obdelnik s cisly\n");
    printf("3 - diagonala\n");
    printf("6 - pismeno T\n");
    printf("9 - obdelnik s cisly v2.0\n");
    scanf("%d", &obrazec);

    printf("Zadejte sirku: \n");
    printf("Zadejte delku: \n");
    scanf("%d%d", &b, &a);

    if (obrazec == 3) {
        a = b;
    }


    printf("Obrazec cislo %d\n", obrazec);
    printf("----------------\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (obrazec == 0) {
                printf("x");
            } else if (obrazec == 1) {
                if (i == 0 || i == a - 1 || j == 0 || j == b - 1) {
                    printf("x");
                } else {
                    printf(" ");
                }
            } else if (obrazec == 2) {
                if (i == 0 || i == a - 1 || j == 0 || j == b - 1) {
                    printf("x");
                } else {
                    printf("%d", cislo);
                    cislo = (cislo + 1) % 10;
                }
            } else if (obrazec == 3) {
                if (i == j) {
                    printf("x");
                } else {
                    printf(" ");
                }
            } else if (obrazec == 6) {
                if (i == 0 || j == b / 2) {
                    printf("x");
                } else {
                    printf(" ");
                }
            } else if (obrazec == 9) {
                if (i == 0 || i == a - 1 || j == 0 || j == b - 1) {
                    printf("x");
                } else {
                    printf("%d", cislo);
                    cislo = (cislo + 1) % 10;
                }
            }
        }
        printf("\n");
    }
    return 0;
}