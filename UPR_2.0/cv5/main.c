#include <stdio.h>
#include <stdlib.h>




void init(int* p, int N){
    for (int i = 0; i < N; i++)
        p[i] = 5;

}

void print_2D(int* p, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; i++)
        {
            p(i * cols + j )=(i * cols + j);
        }
        
    }
    
}

void print_ID(int* p, int N){
    for (int i = 0; i < N; i++)
    {
    printf("%d\n", p[i]);
    }
    

}

void allocate_ID(int** p, int N){
    *p = (int*) malloc(sizeof(int) * N);
}

void deallocate_ID(int* p){
    free(p);
    p = NULL;
}



int main(){

    int rows = 5;
    int cols = 5;
    int N = 10;
    int* p = NULL;
    

    allocate_ID(& p, N);
    init(p, N);
    print_ID(p, N);


    deallocate_ID(&p);

    if (p = NULL)
    {
        printf("deallocation succeeded.\n");
    }

    return 0;
}