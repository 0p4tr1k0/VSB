#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char  idlength;
   char  colourmaptype;
   char  datatypecode;
   char  colourmaporigin[2];
   char  colourmaplength[2];
   char  colourmapdepth;
   char  x_origin[2];
   char  y_origin[2];
   char width[2];
   char height[2];
   char  bitsperpixel;
   char  imagedescriptor;
} TGA_HEADER;

typedef struct{
    char B;
    char G;
    char R;
} PIXEL;


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
    

    FILE* image = fopen("image.tga", "wb");

    fwrite(&header, sizeof(header), 1, image);
    fwrite(pixels, sizeof(PIXEL), width * height, image);


    fclose(image);

    free(pixels);
    pixels= NULL;

    return 0;
}