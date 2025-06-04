#include <stdlib.h>
#include <stdio.h>

int scorri(int valori[], int lenValori, int codice) {
    int *temp = NULL;
    int i;
    int passi;

    temp = malloc(sizeof(int) * lenValori);
    if(temp == NULL) {
        exit(EXIT_FAILURE);
    }

    passi = codice % lenValori;
    if(codice < 0) passi += lenValori;

    for(i = 0; i < lenValori; i++) {
        temp[(i + passi) % lenValori] = valori[i];
    }

    for(i = 0; i < lenValori; i++) {
        valori[i] = temp[i];
    }
    
    free(temp);

    return valori[0];
}

int codifica(int valori[], int lenValori, int codice[], int lenCodice) {
    int i;
    int somma = 0;
    
    for(i = 0; i < lenCodice; i++) {
        somma += scorri(valori, lenValori, codice[i]);
    }

    return somma;
}

int main(void) {
    int valori[] = {3, 1, -4, 2, 0, 5};
    int codice[] = {-2, 3, 1, 8};
    int nVal = sizeof(valori) / sizeof(valori[0]);
    int nCod = sizeof(codice) / sizeof(codice[0]);

    int risultato = codifica(valori, nVal, codice, nCod);
    printf("Somma risultante: %d\n", risultato);

    return 0;
}
