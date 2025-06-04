#include <stdlib.h>
#include <stdio.h>

void crescente(int valori[], int lenValori, int *inizio, int *lunghezza) {
    int i, j;
    int currentLen;
    int check;

    *lunghezza = 0;
    *inizio = 0;

    for(i = 0; i < lenValori; i++) {
        currentLen = 1;
        check = 1;

        for(j = i; j < lenValori - 1 && check; j++) {
            if(valori[j] < valori[j + 1]) {
                currentLen++;
            } else {
                check = 0;
            }
        }

        if(currentLen >= *lunghezza) {
            *lunghezza = currentLen;
            *inizio = i;
        }

        if(currentLen > 1) j = j - 1;
        i = j;
    }
}

int main(void) {
    int valori[] = {2, 1, 4, 7, 3, 6, 11, 12, 21, 15, 4, 8};
    int lenValori = sizeof(valori) / sizeof(valori[0]);

    int indiceInizio;
    int lunghezzaMax;

    crescente(valori, lenValori, &indiceInizio, &lunghezzaMax);

    printf("Sottosequenza crescente massima:\n");
    printf("Indice di inizio = %d\n", indiceInizio);
    printf("Lunghezza = %d\n", lunghezzaMax);

    return 0;
}
