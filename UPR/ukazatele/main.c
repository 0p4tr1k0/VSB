#include <stdio.h>

void tiskHistogramu(int *histogram, int m) {
    printf("Histogram pro rozsah [%d, %d]:\n", m, m + 8);
    for (int i = 0; i < 9; i++) {
        if (m + i < 100) {
            printf(" %d ", m + i);
        } else {
            printf("%d ", m + i);
        }
        for (int j = 0; j < histogram[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
}

void vypocetHistogramu(int *histogram, int *invalid_n, int n, int m) {
    printf("Zadejte %d cisel:\n", n);
    for (int i = 0; i < n; i++) {
        int cislo;
        scanf("%d", &cislo);
        if (cislo >= m && cislo <= m + 8) {
            histogram[cislo - m]++;
        } else {
            (*invalid_n)++;
        }
    }
}

int main() {
    char znak;
    int n, m;
    int histogram[9] = {0};
    int invalid_n = 0;

    printf("Zadejte znak 'h' pro horizontalni histogram nebo 'v' pro vertikalni histogram: ");
    scanf(" %c", &znak);
    printf("\nZadejte pocet cisel (n): ");
    scanf("%d", &n);
    printf("\nZadejte zacatek intervalu (m): ");
    scanf("%d", &m);

    if (znak == 'h') {
        printf("Horizontalni histogram\n");
    } else if (znak == 'v') {
        printf("Vertikalni histogram\n");
    } else {
        printf("Nezvolil jste 'v' nebo 'h'\n");
        return 1;
    }

    if (n < 0) {
        printf("Pocet cisel musi byt nezaporny.\n");
        return 1;
    }

    vypocetHistogramu(histogram, &invalid_n, n, m);

    tiskHistogramu(histogram, m);

    printf("Invalid: ");
    for (int k = 0; k < invalid_n; ++k) {
        printf("#");
    }

    return 0;
}
