/*
#include <stdio.h>
#define MAX 10

int main()
{
    char matrix[MAX][MAX];
    int i;
    int j;
    int row;
    int col;

    printf("Zadejte vysku a sirku pole: ");
    printf("\n");
    scanf("%d %d", &row, &col);


    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            matrix[i][j] = '.';
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
*/

#include <stdio.h>

void print_matrix(int* matrix, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            printf("%d ", matrix[i * cols +j]);
        }
        printf("\n");
    }
}

int main(){
    int vyska = 0;
    int sirka = 0;
    int* pamet_obrazku = (int*) malloc(vyska * sirka * sizeof(int));

    int matrix[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}    
        };
        int rows = 3;
        int cols = 3;
    print_matrix((int*)matrix, rows, cols);
return 0;}