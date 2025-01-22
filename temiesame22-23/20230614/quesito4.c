#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char *nomeFile = argv[1];
    int nr = atoi(argv[2]);
    int nc = atoi(argv[3]);
    char bufferNum[100];
    char bufferRepetition[100];
    int counter = 0;
    int i = 0;

    // Verifica se sono stati passati i giusti argomenti
    if (argc != 4) {
        printf("Uso: %s <file> <numero righe> <numero colonne>\n", argv[0]);
        return 1;
    }
 
    // Apertura del file
    file = fopen(nomeFile, "r");

    if (file == NULL) {
        // If file couldn't be opened, print an error and exit
        perror("Error opening file");
        return 1;
    }

    while (fscanf(file, "%s", bufferNum) == 1 && fscanf(file, "%s", bufferRepetition)) {

        for (i = 0; i < atoi(bufferRepetition); i++) {
            printf("%s  ", bufferNum);

            counter += 1;
            if (counter == nc) {
                printf("\n");
                counter = 0;
            }
        }
    }

    // Visualizzazione dell'array

    return 0;
}