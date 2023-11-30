#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 101
#define MAX_PATH_LENGTH 256

int flagExists(int argc, char* argv[], const char* flag) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], flag) == 0) {
            return 1;
        }
    }
    return 0;
}

void printUsage() {
    fprintf(stderr, "Usage: program_name [-i] [-o output_file] input_file needle\n");
}

void processLine(const char* line, const char* needle, int ignoreCase, FILE* outputFile) {
    if (ignoreCase) {
        char* needleLower = strdup(needle);
        char* lineLower = strdup(line);

        for (int i = 0; needleLower[i]; i++) {
            needleLower[i] = tolower(needleLower[i]);
        }

        for (int i = 0; lineLower[i]; i++) {
            lineLower[i] = tolower(lineLower[i]);
        }

        if (strstr(lineLower, needleLower) != NULL) {
            fprintf(outputFile, "%s\n", line);
        }
        
        free(needleLower);
        free(lineLower);
    } else {
        if (strstr(line, needle) != NULL) {
            fprintf(outputFile, "%s\n", line);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 4 || argc > 6) {
        fprintf(stderr, "Invalid number of arguments\n");
        printUsage();
        return 1;
    }

    char inputPath[MAX_PATH_LENGTH];
    char needle[MAX_LINE_LENGTH];
    int ignoreCase = 0;
    int outputFileFlag = 0;
    char outputPath[MAX_PATH_LENGTH];
    FILE* inputFile;
    FILE* outputFile;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            if (ignoreCase) {
                fprintf(stderr, "Duplicate -i flag\n");
                return 1;
            }
            ignoreCase = 1;
        } else if (strcmp(argv[i], "-o") == 0) {
            if (outputFileFlag) {
                fprintf(stderr, "Duplicate -o flag\n");
                return 1;
            }
            if (i == argc - 1) {
                fprintf(stderr, "Missing output file path\n");
                printUsage();
                return 1;
            }
            outputFileFlag = 1;
            strcpy(outputPath, argv[i + 1]);
            i++;
        } else {
            if (inputPath[0] == '\0') {
                strcpy(inputPath, argv[i]);
            } else if (needle[0] == '\0') {
                strcpy(needle, argv[i]);
            } else {
                fprintf(stderr, "Invalid argument: %s\n", argv[i]);
                printUsage();
                return 1;
            }
        }
    }

    if (inputPath[0] == '\0') {
        fprintf(stderr, "Missing input path\n");
        printUsage();
        return 1;
    }
    if (needle[0] == '\0') {
        fprintf(stderr, "Missing needle\n");
        printUsage();
        return 1;
    }

    inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Failed to open input file\n");
        return 1;
    }

    if (outputFileFlag) {
        outputFile = fopen(outputPath, "w");
        if (outputFile == NULL) {
            fprintf(stderr, "Failed to open output file\n");
            fclose(inputFile);
            return 1;
        }
    } else {
        outputFile = stdout;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), inputFile)) {
        line[strcspn(line, "\n")] = '\0';
        processLine(line, needle, ignoreCase, outputFile);
    }

    fclose(inputFile);
    if (outputFileFlag) {
        fclose(outputFile);
    }

    return 0;
}
