#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Uso: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return 1;
    }

    int numFiles = argc - 1;
    int numFailedToOpen = 0;
    int numEmptyFiles = 0;
    char* fileWithMostChars = NULL;
    int maxChars = 0;

    for (int i = 1; i < argc; i++) {
        FILE* file = fopen(argv[i], "r");
        if (!file) {
            numFailedToOpen++;
            continue;
        }

        int charCount = 0;
        int ch;

        while ((ch = fgetc(file)) != EOF) {
            charCount++;
        }

        if (charCount == 0) {
            numEmptyFiles++;
        }

        if (charCount > maxChars) {
            maxChars = charCount;
            fileWithMostChars = argv[i];
        }

        fclose(file);
    }

    printf("Numero di file: %d\n", numFiles);
    printf("Numero di file non aperti: %d\n", numFailedToOpen);
    printf("Numero di file vuoti: %d\n", numEmptyFiles);
    if (fileWithMostChars != NULL) {
        printf("File con più caratteri: %s (%d caratteri)\n", fileWithMostChars, maxChars);
    } else {
        printf("Nessun file con caratteri trovato.\n");
    }

    return 0;
}
