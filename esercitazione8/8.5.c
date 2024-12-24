#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 10
#define C 15

int main() {
    int M[R][C];
    int i, j;
    int diagonale1;
    int diagonale2;
    int claque = 0;

    srand(time(NULL));

    // Generate random matrix M
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            M[i][j] = rand() % 10 + 1; // Random numbers between 1 and 100
        }
    }

    // Print matrix M
    printf("Matrix M:\n");
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < R - 1; i++) {
        for (j = 0; j < C - 1; j++) {
            diagonale1 = M[i][j] + M[i + 1][j + 1];
            diagonale2 = M[i][j + 1] + M[i + 1][j];
            if(diagonale1 == diagonale2) {
                claque++;
                printf("Claque!\n");
                printf("%d %d\n", M[i][j], M[i][j + 1]);
                printf("%d %d\n\n", M[i + 1][j], M[i + 1][j + 1]);
            }
        }
    }

    printf("Numero di claque: %d\n", claque);
}

// 8.5 Considerata una matrice A di N x M interi, definiamo claque una sotto-
// matrice 2×2 in cui la somma algebrica dei valori di una diagonale sia pari a
// quella dell’altra diagonale. In figura sono evidenziate le claque. Si scriva un
// programma che acquisisce una matrice N x M stampa il numero di claque della
// matrice.