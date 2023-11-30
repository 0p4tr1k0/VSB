#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

void printUsage() {
    printf("Usage: search -i -o <output> <input-path> <needle>\n");
}

const char *stristr(const char *haystack, const char *needle) {
    size_t needleLen = strlen(needle);
    if (needleLen == 0) {
        return haystack;
    }

    while (*haystack) {
        size_t i = 0;
        while (tolower((unsigned char)haystack[i]) == tolower((unsigned char)needle[i])) {
            if (++i == needleLen) {
                return haystack;
            }
        }
        ++haystack;
    }

    return NULL;
}

int main(int argc, char *argv[]) {

    if (argc < 4) {
        printUsage();
        return 1;
    }


    int ignoreCase = 0;
    FILE *outputFile = stdout;
    const char *inputPath = NULL;
    const char *needle = NULL;

    for (int i = 1; i < argc - 2; ++i) {
        if (strcmp(argv[i], "-i") == 0) {
            if (ignoreCase == 1) {
                fprintf(stderr, "Error: Duplicate parameter -i\n");
                return 1;
            }
            ignoreCase = 1;
        } else if (strcmp(argv[i], "-o") == 0) {
            if (outputFile != stdout) {
                fprintf(stderr, "Error: Duplicate parameter -o\n");
                return 1;
            }
            if (i + 1 >= argc) {
                fprintf(stderr, "Error: Missing path after -o\n");
                return 1;
            }
            if ((outputFile = fopen(argv[i + 1], "w")) == NULL) {
                perror("Error opening output file");
                return 1;
            }
            i++;
        }
    }

    inputPath = argv[argc - 2];
    needle = argv[argc - 1];

    if (inputPath == NULL) {
        fprintf(stderr, "Error: Input path missing\n");
        return 1;
    }

    if (needle == NULL) {
        fprintf(stderr, "Error: Needle missing\n");
        return 1;
    }


    FILE *inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }


    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), inputFile) != NULL) {

        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }


        const char *match;
        if (ignoreCase) {
            match = stristr(line, needle);
        } else {
            match = strstr(line, needle);
        }


        if (match != NULL) {
            fprintf(outputFile, "%s\n", line);
        }
    }

    fclose(inputFile);
    if (outputFile != stdout) {
        fclose(outputFile);
    }

    return 0;
}
