#include <stdio.h>

// Dichiarazione del sottoprogramma che implementerai
void calcola_prodotti_scalari(double valori[], double pesi[], int dimValori, int dimPesi, double risultati[]) {
    int i, j;
    int risultato = 0;

    if(dimPesi > dimValori) {
        return;
    }

    for(i = 0; i <= dimValori - dimPesi; i++) {
        risultato = 0;

        for(j = 0; j < dimPesi; j++) {
            risultato += valori[i + j] * pesi[j];
        }

        risultati[i] = risultato;
    }
}

int main() {
    // Inizializzazione degli array di esempio
    double valori[] = {1.0, -2.0, 2.5, -5.0, 1.0};
    double pesi[] = {-3.0, 5.5};
    int dimValori = sizeof(valori) / sizeof(valori[0]);
    int dimPesi = sizeof(pesi) / sizeof(pesi[0]);
    double risultati[dimValori - dimPesi + 1];  // Array per i risultati dei prodotti scalari

    // Chiamata al sottoprogramma
    calcola_prodotti_scalari(valori, pesi, dimValori, dimPesi, risultati);

    // Stampa dei risultati
    printf("Risultati dei prodotti scalari:\n");
    for (int i = 0; i <= dimValori - dimPesi; i++) {
        printf("Risultato %d: %f\n", i, risultati[i]);
    }

    return 0;
}
