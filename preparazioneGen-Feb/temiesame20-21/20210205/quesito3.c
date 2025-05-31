#include <stdio.h>
#include <stdlib.h>

// Dichiarazione del sottoprogramma
double* distanzalineare(double start, double stop, int numero, int escludistop) {
    double *risultati = (double *)malloc(sizeof(double) * numero);
    int i;
    double differenza;

    if(escludistop) {
        differenza = (stop - start) / numero;
    } else {
        differenza = (stop - start) / (numero - 1);
    }

    for (i = 0; i < numero; i++) {
        risultati[i] = start + differenza * i;
    }

    return risultati;
}

int main() {
    // Esempio di valori di input
    double start = 2.0;
    double stop = 3.0;
    int numero = 5;
    int escludistop = 0;  // Cambia a 0 per includere stop

    // Chiamata del sottoprogramma distanzalineare
    double* risultati = distanzalineare(start, stop, numero, escludistop);

    // Stampa dei risultati
    printf("Valori distribuiti:\n");
    for (int i = 0; i < numero; i++) {
        printf("%f ", risultati[i]);
    }
    printf("\n");

    // Libera la memoria allocata
    free(risultati);

    return 0;
}
