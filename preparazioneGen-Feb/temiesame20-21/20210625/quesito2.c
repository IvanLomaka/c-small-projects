#include <stdio.h>

#define NC 8  // Numero di colonne della matrice

// Dichiarazione della funzione
void trovaSegmentoMassimo(int matrice[][NC], int righe, int *rigaInizio, int *colonnaInizio, int *lunghezza) {
    int i, j;
    int controlloJ = 0;
    int lunghezzaControllo = 0;

    for(i = 0; i < righe; i++) {
        lunghezzaControllo = 0;

        for(j = 0; j < NC; j++) {
            if(matrice[i][j] == 1 && lunghezzaControllo == 0) controlloJ = j;

            if(matrice[i][j] == 1) {
                lunghezzaControllo ++;
            } else {
                if(lunghezzaControllo > *lunghezza) {
                    *lunghezza = lunghezzaControllo;
                    *rigaInizio = i;
                    *colonnaInizio = controlloJ;
                }

                lunghezzaControllo = 0;
            }
        }

        if(lunghezzaControllo > *lunghezza) {
            *lunghezza = lunghezzaControllo;
            *rigaInizio = i;
            *colonnaInizio = controlloJ;
        }
    }
}

int main() {
    int matrice[7][NC] = {
        {1, 0, 1, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 1, 1, 1},
        {1, 0, 1, 1, 0, 1, 1, 0}
    };

    int rigaInizio, colonnaInizio, lunghezza;

    // Chiamata alla funzione per trovare il segmento orizzontale più lungo
    trovaSegmentoMassimo(matrice, 7, &rigaInizio, &colonnaInizio, &lunghezza);

    // Stampa del risultato
    printf("Segmento massimo inizia a (%d, %d) con lunghezza %d\n", rigaInizio, colonnaInizio, lunghezza);

    return 0;
}
