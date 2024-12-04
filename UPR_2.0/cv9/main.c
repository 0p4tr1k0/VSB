#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tga.h"
#include "tga.c"

int main(){

    int width = 1920;

    int height = 1080;


    TGA_HEADER header = {0,0,2, {0}, {0}, 0, {0}, {0}, {0}, {0}, 24, 32};

    memcpy(header.width, &width, 2);

    memcpy(header.height, &height, 2);

    PIXEL* pixels = (PIXEL*)malloc(sizeof(PIXEL) * width * height);

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int i = y * width + x;

            pixels[i].R = 255;
            pixels[i].G = (x * y)% 15;
            pixels[i].B = 0;
        }
        
    }
    
    save_tga(header, pixels, "image.tga");

    free(pixels);
    pixels= NULL;

    return 0;
}

