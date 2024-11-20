#include <stdio.h>
#include <stdbool.h>


void power(int a,int* N,int* result){

  for (int i = 0; i < N; i++)
  {
    *result = *result *= a;
  }
  
  
  
}


int main(){

    int a = 5;
    int result = 1;
    int N;

    power(a, 3, &result);
    printf("%d\n", a);
    printf("%d\n", result);
    return 0;
}