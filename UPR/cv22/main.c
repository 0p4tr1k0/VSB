#include <stdio.h>

int main(){
int rok;

printf("Zadej rok: \n");
scanf("%d", &rok);

if(rok%4==0 && rok%100!=0 || rok%400==0 ){
    printf("rok %d je prestupny.\n",rok);
}else{
    printf("rok %d neni prestupny.\n",rok);
}




return 0;}