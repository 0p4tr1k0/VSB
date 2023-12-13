#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char byte;

typedef struct TGAreader_ TGAreader;

struct TGAHeader_ {
    byte
    byte
    byte
    byte
    byte
    byte
    byte
    byte
    byte
    byte
} TGAHeader_;

int tgaheader_width(const TGAreader * self){
    int width = 0;
    memcpy(&width, self->width, 2);
    return width;
}

int tgaheader_height(const TGAreader * self){
    int height = 0;
    memcpy(&height, self->width, 2);
    return height;
}

typedef struct TGA_ TGA;

struct TGA{
    TGAHeader header;
    byte * data;
}

int main(){
    int width = 640;
    int height = 480;

    TGA * tga = tga_ 
}