#include <stdio.h>

// External functions that will be implemented in assembly
extern int count_odd_numbers(int g_int_array[], int size, int *g_int_outup);
extern void move_negative_numbers(int g_int_array[], int size, int g_neg_val_array[]);
extern int count_vowels(char g_char_array[], int size);
extern void replace_third_char(char g_char_array[], int size);

int main() {
    // Test data as defined in the first image
    int g_int_array[15] = { -3, -8, 80, 2710, 32, 439, 9099, 10, 77, -273, 2, 22222, 0, -23, 23};
    char g_char_array[32] = "testovací pole pro cv2";
    
    // Arrays to store results
    int g_int_outup = 0;
    int g_neg_val_array[15] = {0};
    
    // 1. Count odd numbers in the array
    int odd_count = count_odd_numbers(g_int_array, 15, &g_int_outup);
    printf("Number of odd numbers: %d\n", odd_count);
    printf("Last 4 bytes value stored in g_int_outup: %d\n", g_int_outup);
    
    // 2. Move negative numbers to a new array
    move_negative_numbers(g_int_array, 15, g_neg_val_array);
    printf("Negative numbers moved to g_neg_val_array: ");
    for (int i = 0; i < 15 && g_neg_val_array[i] != 0; i++) {
        printf("%d ", g_neg_val_array[i]);
    }
    printf("\n");
    
    // 3. Count vowels in the character array
    int vowel_count = count_vowels(g_char_array, 32);
    printf("Number of vowels in '%s': %d\n", g_char_array, vowel_count);
    
    // 4. Replace every third character with '3'
    printf("Original string: %s\n", g_char_array);
    replace_third_char(g_char_array, 32);
    printf("After replacing every third character: %s\n", g_char_array);
    
    return 0;
}
