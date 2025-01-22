#include <stdio.h>

// Dichiarazione del sottoprogramma
int baricentro(int array[], int lunghezza) {
    int somma = 0;
    int i;
    int i1, j1;

    for (i = 0; i < lunghezza; i++) {
        somma = 0;

        for(i1 = 0; i1 <= i; i1++) {
            somma += array[i];
        }

        for(j1 = i + 1; j1 < lunghezza; j1++) {
            somma -= array[i];
        }

        if(somma == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    // Definizione e inizializzazione dell'array di esempio
    int array[] = { 1,2,3,4,5,1,2,3,4,5 };
    int lunghezza = sizeof(array) / sizeof(array[0]);

    // Chiamata del sottoprogramma baricentro
    int indice = baricentro(array, lunghezza);

    // Stampa del risultato
    if (indice != -1) {
        printf("L'indice del baricentro è: %d\n", indice);
    } else {
        printf("Non esiste un baricentro.\n");
    }

    return 0;
}
