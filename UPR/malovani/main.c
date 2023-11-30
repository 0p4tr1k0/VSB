#include "drawing.h"
#include <stdio.h>
#include <stdlib.h>


void random_barva(){
     
      int  cislo_barvy = rand() % 6 + 1; 
        if (cislo_barvy == 1){
            set_black_color();
        }else if (cislo_barvy == 2){
            set_green_color();
        }else if (cislo_barvy == 3){
            set_blue_color();
        }else if (cislo_barvy == 4){
            set_red_color();
        }else if (cislo_barvy == 5){
            set_white_color();
        }else if (cislo_barvy == 6){
            set_yellow_color();
        }
     }  

void prerusovana_cara(int delka_obrazu) {
    for (int i = 0; i < delka_obrazu; i++) {
        if (i % 2 == 0) {
            random_barva();
        } else {
            reset_color();
        }
        draw_pixel();
        move_right();
    }
}

void schody(int delka_obrazu) {
    for (int i = 0; i < delka_obrazu; i++) {
        random_barva();
        draw_pixel();
        move_right();
        move_down();
    }
}
void kytka(int delka_obrazu){
    
    for (int i = 0; i < delka_obrazu; i++) {
        set_yellow_color();
        draw_pixel();
        if (i % 1 == 0) {
            move_down();
            set_red_color();
        } else {
            set_green_color();
        }
    }
        move_right();
    
    
    set_green_color();
    draw_pixel();

}


int main(){
    clear_screen();
    int cislo = 0;
    int delka_obrazu = 0;
    printf("0 - presurovane cary na ruznych pozicich s ruznou barvou\n");
    printf("1 - schody\n");
    printf("2 - kvetiny\n");
    printf("3 - louka kvetin\n");
    printf("4 - animace\n");
    printf("\n");
    printf("Zadejte cislo 0-4: \n");
    scanf("%d", &cislo);
    printf("Zadejte delku (delka obsahuje i mezery u prerusovane cary): \n");
    scanf("%d", &delka_obrazu);


    if(cislo == 0){
        printf("0 - presurovane cary na ruznych pozicich s ruznou barvou\n");
        prerusovana_cara(delka_obrazu);
    }else if(cislo == 1){
        printf("1 - schody\n");
        schody(delka_obrazu);
    }else if(cislo == 2){
        printf("2 - kvetiny\n");
        kytka(delka_obrazu);
    }else if(cislo == 3){
        printf("3 - louka kvetin\n");
    }else if(cislo == 4){
        printf("4 - animace\n");
    }
    end_drawing();
return 0;}