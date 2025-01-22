#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct slista_t {
    char parola[31];
    struct slista_t *Next;
} slista_t;

char **cerca(char parola[]) {
    int parolaLen = strlen(parola);
    int aggiungi = 1;
    int i;
    int size = 3;
    char buffer[36];
    int dim = 0;

    FILE *fileSorgente = fopen("dizionario.txt", "r");
    if(fileSorgente == NULL) {
        printf("Errore di file\n");
        return "Error";
    }

    char **array = malloc(size * sizeof(char*));
    if (array == NULL) {
        printf("Errore di allocazione della memoria\n");
        return "Error";
    }
    
    while(fgets(buffer, sizeof(buffer), fileSorgente) != NULL) {
        aggiungi = 1;

        if(dim == size) {
            size += 3;
            array = realloc(array, size * sizeof(char *));
            if(array == NULL) {
                printf("Errore di allocazione della memoria\n");
                return "Error";
            }
        }

        for(i = 1; i < parolaLen; i++) {
            if(parola[i] != buffer[i]) {
                aggiungi = 0;
            }
        }

        if(strlen(buffer) == parolaLen + 1 && aggiungi) {
            array[dim] = (char *)malloc(parolaLen * sizeof(char *));
            if(array[dim] == NULL) {
                printf("Errore di allocazione della memoria\n");
                return "Error";
            }

            dim += 1;
        }
    }

    return array;
}

int main() {
    char **risultato = cerca("pela");

    if (risultato == NULL) {
        printf("Errore durante la ricerca\n");
        return 1;
    }

    printf("\nParole trovate:\n");
    for (int i = 0; risultato[i] != NULL; i++) {
        printf("%s\n", risultato[i]);
        free(risultato[i]); // Libera memoria per ogni stringa
    }
    free(risultato); // Libera memoria per l'array

    return 0;
}