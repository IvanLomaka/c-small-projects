#include <stdio.h>
#include <stdlib.h>

// Intestazione della funzione richiesta
double* cercabassi(double arr[], int n, int *numBassI) {
    int i = 0;
    int dimensione = 0;
    double *numBassi = (double *)malloc(sizeof(double) * n);
    if(numBassi == NULL) {
        return NULL;
    }

    for (i = 1; i < n - 1; i++) {
        if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            numBassi[dimensione] = arr[i];
            dimensione++;
        }
    }

    *numBassI = dimensione;

    numBassi = (double *)realloc(numBassi, sizeof(double) * (dimensione ));
    if(numBassi == NULL) {
        return NULL;
    }

    return numBassi;
}

int main() {
    double *bassi;
    double *valori;
    int n, i;
    int numBassi = 0;
    int check = 1;
    
    // Input per la dimensione dell'array
    while(scanf("%d", &n) != 1 || n <= 0) {
        printf("Inserisci un numero valido di elementi: ");
        while(getchar() != '\n');  // Pulisce il buffer
    }

    // Allocazione dell'array per i valori
    valori = (double *)malloc(sizeof(double) * n);
    if(valori == NULL) {
        printf("Errore nell'allocazione della memoria!\n");
        return 1;
    }

    // Input dei valori
    for (i = 0; i < n; i++) {
        scanf("%lf", &valori[i]);
    }

    bassi = cercabassi(valori, n, &numBassi);
    
    // Stampa dei valori bassi
    if(bassi != NULL) {
        for (i = 0; i < numBassi; i++) {
            printf("%lf ", bassi[i]);
        }
        printf("\n");

        free(bassi);  // Libera la memoria allocata dinamicamente
    }

    free(valori);  // Libera l'array iniziale
    return 0;
}
