#include <stdio.h>

#define NC 5  // Numero di colonne per la matrice, puoi cambiare il valore a seconda delle necessità

// Intestazione della funzione per l'aggiornamento dopo l'eruzione
void eruzione(int matrice[][NC], int riga, int colonna, int righe) {


    // controlla le caselle in alto
    if(riga > 0) {
        if (colonna > 0) {
            if (matrice[riga - 1][colonna - 1] < matrice[riga][colonna]) {
                matrice[riga - 1][colonna - 1] += 1;
            }

            if (matrice[riga][colonna - 1] < matrice[riga][colonna]) {
                matrice[riga][colonna - 1] += 1;
            }
        }

        if (matrice[riga - 1][colonna] < matrice[riga][colonna]) {
            matrice[riga - 1][colonna] += 1;
        }

        if (colonna < NC - 1) {
            if (matrice[riga - 1][colonna + 1] < matrice[riga][colonna]) {
                matrice[riga - 1][colonna + 1] += 1;
            }

            if (matrice[riga][colonna + 1] < matrice[riga][colonna]) {
                matrice[riga][colonna + 1] += 1;
            }
        }
    }

    if(riga < righe - 1) {
        if (colonna > 0) {
            if (matrice[riga + 1][colonna - 1] < matrice[riga][colonna]) {
                matrice[riga + 1][colonna - 1] += 1;
            }
        }

        if (matrice[riga + 1][colonna] < matrice[riga][colonna]) {
            matrice[riga + 1][colonna] += 1;
        }

        if (colonna < NC - 1) {
            if (matrice[riga + 1][colonna + 1] < matrice[riga][colonna]) {
                matrice[riga + 1][colonna + 1] += 1;
            }
        }
    }

    matrice[riga][colonna] += 2;
}

int main() {
    int matrice[8][NC] = {
        {3, 0, 6, 1, 5},
        {1, 5, 6, 0, 5},
        {4, 6, 5, 6, 1},
        {0, 0, 0, 0, 5},
        {3, 0, 4, 1, 2},
        {1, 5, 1, 3, 1},
        {1, 5, 6, 2, 3},
        {3, 1, 8, 1, 0}
    };
    
    int rigaVulcano = 1, colonnaVulcano = 2;

    // Chiamata alla funzione per aggiornare la matrice
    eruzione(matrice, rigaVulcano, colonnaVulcano, 8);

    // Stampa la matrice aggiornata
    int i, j = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < NC; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    return 0;
}
