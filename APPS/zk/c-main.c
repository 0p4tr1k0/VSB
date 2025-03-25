#include <stdio.h>

// Function declarations with correct types
extern void jen_prvocisla(long *pole, int velikost);
extern void bubble(int *pole, int velikost, int smer);
extern int pocet_malych_pismen(const char *retezec);

int main() {
    int velikost = 10;
    long prvocisla[10];
    int bubbleSort[10] = {5, 2, 9, 1, 7, 6, 3, 8, 4, 0};
    int bubbleSortCopy[10];
    
    // Test string for counting lowercase letters
    const char *test_string = "Hello World! Toto je TestovaCi Retezec.";

    // Initialize the array with values
    for (int i = 0; i < velikost; i++) {
        prvocisla[i] = i + 1;
        bubbleSortCopy[i] = bubbleSort[i];
    }

    // Call the assembly functions
    jen_prvocisla(prvocisla, velikost);
    
    // Sort in ascending order
    bubble(bubbleSort, velikost, 1);
    
    // Sort in descending order
    bubble(bubbleSortCopy, velikost, 0);
    
    // Count unique lowercase letters
    int unique_lowercase = pocet_malych_pismen(test_string);

    // Print results
    printf("Prvočísla po úpravě:\n");
    for (int i = 0; i < velikost; i++) {
        printf("%ld ", prvocisla[i]);
    }
    
    printf("\n\nPole seřazené vzestupně:\n");
    for (int i = 0; i < velikost; i++) {
        printf("%d ", bubbleSort[i]);
    }
    
    printf("\n\nPole seřazené sestupně:\n");
    for (int i = 0; i < velikost; i++) {
        printf("%d ", bubbleSortCopy[i]);
    }
    
    printf("\n\nPočet různých malých písmen: %d\n", unique_lowercase);

    return 0;
}