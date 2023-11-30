#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    int den;
    char *nazev_akcie;
    double hodnota_akcie_Z;
    double hodnota_akcie_N;
    int provedene_obchody;
} StockRecord;

void uvolni_zaznamy_akcii(StockRecord *zaznamy_akcii, int pocet_radku) {
    for (int i = 0; i < pocet_radku; i++) {
        free(zaznamy_akcii[i].nazev_akcie);
    }
    free(zaznamy_akcii);
}

void nacti_zaznamy_akcii(StockRecord *zaznamy_akcii, int pocet_radku) {


    for (int i = 0; i < pocet_radku; i++) {
        printf("Den %d: ", i + 1);

        zaznamy_akcii[i].nazev_akcie = (char *) malloc(MAX_LINE_LENGTH);
        if (zaznamy_akcii[i].nazev_akcie == NULL) {
            printf("Alokace pameti selhala.\n");
            exit(1);
        }

        if (scanf("%d,%99[^,],%lf,%lf,%d",
                  &zaznamy_akcii[i].den,
                  zaznamy_akcii[i].nazev_akcie,
                  &zaznamy_akcii[i].hodnota_akcie_Z,
                  &zaznamy_akcii[i].hodnota_akcie_N,
                  &zaznamy_akcii[i].provedene_obchody) != 5) {
            printf("Neplatny format vstupu.\n");
            exit(1);
        }
    }
}

int najdi_index_maximalnich_obchodu(StockRecord *zaznamy_akcii, int pocet_radku, const char *hledana_akcie) {
    int maximalni_obchody = -1;
    int index_maximalnich_obchodu = -1;

    for (int i = 0; i < pocet_radku; i++) {
        if (strcmp(zaznamy_akcii[i].nazev_akcie, hledana_akcie) == 0) {
            if (zaznamy_akcii[i].provedene_obchody > maximalni_obchody) {
                maximalni_obchody = zaznamy_akcii[i].provedene_obchody;
                index_maximalnich_obchodu = i;
            }
        }
    }
    return index_maximalnich_obchodu;
}
void
generuj_html_tabulku(char *nazev_akcie, int pocet_radku, StockRecord *zaznamy_akcii, int index_zvyrazneneho_zaznamu) {
    printf("<html>\n<head>\n<title>%s Informace o Akcii</title>\n</head>\n<body>\n", nazev_akcie);
    printf("<h1>%s Informace o Akcii</h1>\n", nazev_akcie);
    printf("<table border=\"1\">\n");
    printf("<tr><th>Index Dne</th><th>Nazev Akcie</th><th>Hodnota na Zacatku Dne</th><th>Hodnota na Konci Dne</th>"
           "<th>Počet Provedených Obchodů</th></tr>\n");

    for (int i = pocet_radku - 1; i >= 0; i--) {
        printf("<tr>\n");

        if (i == index_zvyrazneneho_zaznamu) {
            printf("<td><b>%d</b></td>\n", zaznamy_akcii[i].den);
            printf("<td><b>%s</b></td>\n", zaznamy_akcii[i].nazev_akcie);
            printf("<td><b>%.2f</b></td>\n", zaznamy_akcii[i].hodnota_akcie_Z);
            printf("<td><b>%.2f</b></td>\n", zaznamy_akcii[i].hodnota_akcie_N);
            printf("<td><b>%d</b></td>\n", zaznamy_akcii[i].provedene_obchody);
        } else {
            printf("<td>%d</td>\n", zaznamy_akcii[i].den);
            printf("<td>%s</td>\n", zaznamy_akcii[i].nazev_akcie);
            printf("<td>%.2f</td>\n", zaznamy_akcii[i].hodnota_akcie_Z);
            printf("<td>%.2f</td>\n", zaznamy_akcii[i].hodnota_akcie_N);
            printf("<td>%d</td>\n", zaznamy_akcii[i].provedene_obchody);
        }
        printf("</tr>\n");
    }
    printf("</table>\n</body>\n</html>\n");
}

int main(int argc, char **argv) {
    if(argc < 3){
        printf("Wrong parameters\n");
        return 1;
    }
    int pocet_radku = atoi(argv[2]);


    if (pocet_radku <= 0) {
        printf("Neplatny pocet radku. Zadejte prosim kladne cele cislo.\n");
        return 1;
    }
    StockRecord *zaznamy_akcii = (StockRecord *) malloc(pocet_radku * sizeof(StockRecord));

    if (zaznamy_akcii == NULL) {
        printf("Alokace pameti selhala.\n");
        return 1;
    }
    nacti_zaznamy_akcii(zaznamy_akcii, pocet_radku);

    char* hledana_akcie = argv[1];
    int index_zvyrazneneho_zaznamu = najdi_index_maximalnich_obchodu(zaznamy_akcii, pocet_radku, hledana_akcie);

    if (index_zvyrazneneho_zaznamu != -1) {
        generuj_html_tabulku(zaznamy_akcii[0].nazev_akcie, pocet_radku, zaznamy_akcii, index_zvyrazneneho_zaznamu);
    } else {
        printf("<html>\n<head>\n<title>Informace o Akcii</title>\n</head>\n<body>\n");
        printf("<p>Informace o akcii %s nebyla nalezena.</p>\n", hledana_akcie);
        printf("</body>\n</html>\n");
    }
    uvolni_zaznamy_akcii(zaznamy_akcii, pocet_radku);

    return 0;
}
