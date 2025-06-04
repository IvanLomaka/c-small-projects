#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *nuovaStringa(char input[], int ripetizioni[]) {
    int i, j;
    int len = strlen(input);
    int dim = 0;
    int countDim;

    char *output;

    for(i = 0; i < len; i++) {
        dim += ripetizioni[i];
    }
    
    output = malloc(sizeof(char) * (dim + 1));
    if(output == NULL) return NULL;

    countDim = 0;
    
    for(i = 0; i < len; i++) {
        for(j = 0; j < ripetizioni[i]; j++) {
            output[countDim] = input[i];
            countDim++;
        }
    }

    output[countDim] = '\0';

    return output;
}

int main(void) {
    char car[] = "abcd";
    int rip[] = {1, 3, 0, 2};

    char *risultato = nuovaStringa(car, rip);

    if (risultato != NULL) {
        printf("Stringa risultante: %s\n", risultato);
        free(risultato);
    } else {
        printf("Errore nell'allocazione della memoria.\n");
    }

    return 0;
}
