#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int conta_sottomatrici(int mappa[3][3], int dimh, int dimv) {
    int aggiungi = 1;
    int contatore = 0;

    int i, j, i1, j1;

    for (i = 0; i <= 3 - dimv; i++) {
        for (j = 0; j <= 3 - dimh; j++) {
            aggiungi = 1;

            for(i1 = 0; i1 < dimv; i1++) {
                for(j1 = 0; j1 < dimh; j1++) {
                    if(mappa[i + i1][j + j1] < 0) aggiungi = 0;
                }
            }

            if (aggiungi) {
                contatore++;
            }            
        }
    }

    return contatore++;
}

int main() {
    int dimh = 2, dimv = 2; // Dimensioni della sotto-matrice
    int mappa[3][3]; // Mappa di dimensione 3x3
    int count;

    srand(time(NULL)); // Per generare numeri casuali diversi ogni volta

    // Genera numeri casuali per la mappa
    printf("Mappa (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mappa[i][j] = rand() % 10 - 5; // Numeri tra -5 e 4 (incluso)
            printf("%d ", mappa[i][j]);
        }
        printf("\n");
    }

    // Chiamata al sottoprogramma per contare le sotto-matrici
    count = conta_sottomatrici(mappa, dimh, dimv);

    // Stampa il risultato
    printf("Numero di sotto-matrici con valori strettamente positivi: %d\n", count);

    return 0;
}