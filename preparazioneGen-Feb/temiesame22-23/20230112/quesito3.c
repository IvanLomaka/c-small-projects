#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 31  // 30 caratteri + terminatore di stringa

int main() {
    char filename[MAX_FILENAME_LENGTH];
    FILE *file;
    int totalCharacters = 0;
    int maxCharacters = 0;
    char maxFilename[MAX_FILENAME_LENGTH];
    int fileInacessibile = 0;
    int charCount = 0;
    char c;

    printf("Inserisci i nomi dei file (termina con un file non accessibile):\n");

    while(!fileInacessibile) {
        printf("Nome del file: ");
        scanf("%30s", filename);

        file = fopen(filename, "r");
        if (file == NULL) {
            printf("File non accessibile o inesistente. Terminazione del programma.\n");
            break;
        } else {
            while ((c = fgetc(file)) != EOF) {
                charCount++;
            }

            fclose(file);

            printf("Il file '%s' contiene %d caratteri.\n", filename, charCount);

            totalCharacters += charCount;

            if (charCount > maxCharacters) {
                maxCharacters = charCount;
                strcpy(maxFilename, filename);
            }
        }

        printf("Numero totale di caratteri: %d\n", totalCharacters);
        if (maxCharacters > 0) {
            printf("Il file con più caratteri è '%s' con %d caratteri.\n", maxFilename, maxCharacters);
        }
    }

    return 0;
}