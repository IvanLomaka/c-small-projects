#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareChar(char uno, char due) {
    uno = (uno >= 'A' && uno <= 'Z') ? uno - 'A' + 'a' : uno;
    due = (due >= 'A' && due <= 'Z') ? due - 'A' + 'a' : due;

    return (uno == due);
}

int compare(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0;

    if(len1 != len2) return 1;

    for(i = 0; i < len1; i++) {
        if(compareChar(str1[i], str2[i]) != 1) return 1;
    }

    return 0;
}

int omesso(char nomeSrc[], char nomeDst[], char voc[]) {
    int omesso = 0;
    FILE *filesorgente = NULL;
    FILE *filedestinazione = NULL;

    char c;
    char *buffer = (char *)malloc(sizeof(char) * 30);
    if(buffer == NULL) return -1;

    int dimensione = 30;
    int counter = 0;

    filesorgente = fopen(nomeSrc, "r");
    if(filesorgente == NULL) return -1;

    filedestinazione = fopen(nomeDst, "w");
    if(filedestinazione == NULL) return -1;

    while((c = fgetc(filesorgente)) != EOF) {
        if(c != ' ' && c != '\n') {
            if(counter >= dimensione) {
                dimensione = dimensione + 10;
                buffer = realloc(buffer, sizeof(char) * (dimensione));
                if(buffer == NULL) return -1;
            }

            buffer[counter] = c;
            counter++;
        } else {
            if(counter > 0) {
                if(counter >= dimensione) {
                    dimensione = dimensione + 10;
                    buffer = realloc(buffer, sizeof(char) * (dimensione));
                    if(buffer == NULL) return -1;
                }

                buffer[counter] = '\0';

                if(compare(buffer, voc) == 0) {
                    omesso ++;
                } else {
                    fputs(buffer, filedestinazione);
                    fputc(c, filedestinazione);
                }

                counter = 0;
            }
        }
    }

    fclose(filesorgente);
    fclose(filedestinazione);
    free(buffer);

    return omesso;
}

int main(int argc, char *argv[]) {
    int caratteriOmessi;

    if(argc != 4) return 1;

    caratteriOmessi = omesso(argv[argc - 3], argv[argc - 2], argv[argc - 1]);

    printf("Caratteri omessi: %d\n", caratteriOmessi);
}