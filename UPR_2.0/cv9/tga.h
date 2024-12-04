#pragma once

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

void save_tga(TGA_HEADER header, PIXEL* pixels, char* filename);