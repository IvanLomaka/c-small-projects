#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int verificaIntervallo(int v[], int dim, int da, int a) {
    int i;
    int *valori;
    int

    valori = malloc(sizeof(int) * (a - da + 1));
    if (valori == NULL) exit(EXIT_FAILURE);

    for (i = 0; i < (a - da + 1); i++) {
        valori[i] = 0;
    }

    for (i = 0; i < dim; i++) {
        if(v[i] >= da && v[i] <= a) {
            if(valori[v[i] - da] == 1) {
                free(valori);
                return 0;
            }
            valori[v[i] - da] = 1;
        } else {
            free(valori);
            return 0;
        }
    }

    for (i = 0; i < (a - da + 1); i++) {
       if(valori[i] != 1) return 0;
    }

    return 1;
}

int main(void) {
    int v[DIM] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // esempio corretto per da=5, a=14
    int da = 5;
    int a = 14;

    if (verificaIntervallo(v, DIM, da, a)) {
        printf("L'array contiene tutti e soli i valori distinti nell'intervallo [%d, %d].\n", da, a);
    } else {
        printf("L'array NON contiene tutti e soli i valori distinti nell'intervallo [%d, %d].\n", da, a);
    }

    return 0;
}
