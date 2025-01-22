#include <stdio.h>

void trova_sottovettore_max(double valori[], double pesi[], int *indice, double *risultato, int dimValori, int dimPesi) {
    int risultatoNow = 0;
    int i, j;

    if(dimPesi > dimValori) {
        *indice = -1;
        *risultato = 0;
        return;
    }

    *risultato = 0;
    *indice = 0;

    for (j = 0; j < dimPesi; j++) {
        *risultato += valori[j] * pesi[j];
    }

    for(i = 0; i <= dimValori - dimPesi; i++) {
        risultatoNow = 0;

        for (j = 0; j < dimPesi; j++) {
            risultatoNow += valori[i + j] * pesi[j];
        }

        if(risultatoNow > *risultato) {
            *risultato = risultatoNow;
            *indice = i;
        }
    }
}

int main() {
    // Inizializzazione degli array valori e pesi
    double valori[] = {1.0, -2.0, 2.5, -5.0};
    double pesi[] = {-3.0, 5.5};

    int indice;
    double risultato;

    // Chiamata al sottoprogramma
    trova_sottovettore_max(valori, pesi, &indice, &risultato, 4, 2);

    // Stampa del risultato
    if (indice != -1) {
        printf("Il sottovettore che massimizza il prodotto scalare parte dall'indice %d e ha risultato %.2lf\n", indice, risultato);
    } else {
        printf("Impossibile calcolare il prodotto scalare.\n");
    }

    return 0;
}

