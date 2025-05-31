#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *filesorgente;
    FILE *filedestinazione;
    char buffer[81];
    int i = 0;
    int  wrote = 0;

    if(argc != 3) {
        return 1;
    }

    filesorgente = fopen(argv[argc - 2], "r");
    if(filesorgente == NULL) return 1;


    filedestinazione = fopen(argv[argc - 1], "w");
    if(filedestinazione == NULL) return 1;

    while(fgets(buffer, sizeof(buffer), filesorgente) != NULL) {
        i = 0;
        wrote = 0;

        while(buffer[i] != '\n' && !wrote) {
            if(buffer[i] != ' ') {
                fputs(buffer, filedestinazione);
                wrote = 1;
            }

            i++;
        }
    }

    fclose(filesorgente);
    fclose(filedestinazione);

    return 0;
}