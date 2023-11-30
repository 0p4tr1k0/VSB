#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktura pro hlavičku TGA souboru
typedef struct {
    char idLength;
    char colorMapType;
    char imageType;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
} TGAHeader;

// Funkce pro načtení TGA souboru
unsigned char* readTGA(const char* filename, TGAHeader* header) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    fread(header, sizeof(TGAHeader), 1, file);

    unsigned int imageSize = header->width * header->height * (header->bitsPerPixel / 8);
    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, imageSize, 1, file);

    fclose(file);
    return imageData;
}

// Funkce pro zápis TGA souboru
void writeTGA(const char* filename, const TGAHeader* header, const unsigned char* imageData) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    fwrite(header, sizeof(TGAHeader), 1, file);

    unsigned int imageSize = header->width * header->height * (header->bitsPerPixel / 8);
    fwrite(imageData, imageSize, 1, file);

    fclose(file);
}

// Funkce pro načtení fontu
unsigned char** loadFont(const char* fontPath) {
    unsigned char** font = (unsigned char**)malloc(26 * sizeof(unsigned char*));
    char filename[10];

    for (int i = 0; i < 26; i++) {
        snprintf(filename, sizeof(filename), "%s/%c.tga", fontPath, i + 'A');
        TGAHeader fontHeader;
        font[i] = readTGA(filename, &fontHeader);
        if (font[i] == NULL) {
            printf("Could not load font image %s\n", filename);
            exit(1);
        }
    }

    return font;
}

// Funkce pro vykreslení řádku textu do obrázku
void drawTextLine(unsigned char* image, const TGAHeader* imageHeader, const unsigned char** font, int row, const char* text) {
    int x = 0;
    int y = row * 34;

    for (int i = 0; i < strlen(text); i++) {
        char ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 'a' + 'A'; // Převod malého písmena na velké
        }

        if (ch >= 'A' && ch <= 'Z') {
            unsigned char* charImage = font[ch - 'A'];

            int charWidth = charImage[12] + (charImage[13] << 8);
            int charHeight = charImage[14] + (charImage[15] << 8);

            for (int cy = 0; cy < charHeight; cy++) {
                for (int cx = 0; cx < charWidth; cx++) {
                    int imageX = x + cx;
                    int imageY = y + cy;

                    if (imageX >= 0 && imageX < imageHeader->width && imageY >= 0 && imageY < imageHeader->height) {
                        unsigned char* pixel = &image[(imageY * imageHeader->width + imageX) * (imageHeader->bitsPerPixel / 8)];
                        unsigned char* charPixel = &charImage[(cy * charWidth + cx) * (imageHeader->bitsPerPixel / 8)];

                        if (charPixel[0] != 0 || charPixel[1] != 0 || charPixel[2] != 0) {
                            pixel[0] = charPixel[0];
                            pixel[1] = charPixel[1];
                            pixel[2] = charPixel[2];
                        }
                    }
                }
            }

            x += charWidth;
        } else if (ch == ' ') {
            x += 10; // Mezera mezi znaky
        }
    }
}

int main(int argc, char* argv[]) {
    // Kontrola počtu argumentů
    if (argc != 4) {
        printf("Wrong parameters\n");
        return 1;
    }

    const char* inputFilename = argv[1];
    const char* outputFilename = argv[2];
    const char* fontPath = argv[3];

    // Načtení vstupního TGA souboru
    TGAHeader inputHeader;
    unsigned char* inputImage = readTGA(inputFilename, &inputHeader);
    if (inputImage == NULL) {
        printf("Could not load image\n");
        return 1;
    }

    // Načtení fontu
    unsigned char** font = loadFont(fontPath);

    // Načtení top a bottom hodnot ze vstupu
    int top, bottom;
    scanf("%d %d", &top, &bottom);
    getchar();

    // Načtení top + bottom řádků textu
    char line[101];
    char text[300];
    text[0] = '\0';

    for (int i = 0; i < top + bottom; i++) {
        fgets(line, sizeof(line), stdin);
        strcat(text, line);
    }

    // Vykreslení textu do vstupního obrázku
    drawTextLine(inputImage, &inputHeader, (const unsigned char**)font, top, text);

    // Zápis upraveného obrázku do výstupního souboru s původní hlavičkou
    writeTGA(outputFilename, &inputHeader, inputImage);

    // Uvolnění paměti
    free(inputImage);
    for (int i = 0; i < 26; i++) {
        free(font[i]);
    }
    free(font);

    return 0;
}
