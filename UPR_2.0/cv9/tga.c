#pragma once
#include "tga.h"
#include <stdio.h>
#include<string.h>


void save_tga(TGA_HEADER header, PIXEL* pixels, char* filename){

    int width = 0;
    int height = 0;

    memcpy(&width, header.width, 2);
    memcpy(&height, header.height, 2);
    
    FILE* image = fopen("image.tga", "wb");

    fwrite(&header, sizeof(header), 1, image);
    fwrite(pixels, sizeof(PIXEL), width * height, image);


    fclose(image);
}