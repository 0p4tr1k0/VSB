#include <stdio.h>
#include <stdlib.h>





void sum_array(int* a, int N, int* result){

    int M = N /2;

    for (int i = 0; i < M - N % 2; i++)
    {
        result[i] = a[i * 2]+ a[i * 2 + 1];
    }
    

}


int main(){

    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int N = sizeof(a) / sizeof(a[0]);


    

    int result(6);

    sum_array(a, N, result);

    return 0;

}