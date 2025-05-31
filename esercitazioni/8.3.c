#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    int M[N][N];
    int A[N];

    srand(time(NULL));

    // Generate random matrix M
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            M[i][j] = ((rand() % 40) + 1) * 5; // Random numbers between 1 and 100
        }
    }

    // Generate random array A
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 10 + 1; // Random numbers between 1 and 100
    }

    // Print matrix M
    printf("Matrix M:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    // Print array A
    printf("Array A:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");

    int arrayNum;
    int i, j;
    int divisoreTrovato = 1;

    for (arrayNum = 0; arrayNum < N; arrayNum++) {

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (M[i][j] % A[arrayNum] != 0) divisoreTrovato = 0;
            }

            if (divisoreTrovato) {
                printf("Numero: %d ", A[arrayNum]);
                printf("Riga: %d ", i + 1);
                break;
            } else {
                divisoreTrovato = 1;
            }
        }

        if (divisoreTrovato) break;
    }

    printf("\n");

    return 0;
}

// 8.3 Si scriva un programma che acquisisce una matrice quadrata NxN (con N
// costante predefinita con l’istruzione #define N . . . ) di interi positivi M ed un
// array A di dimensione N. La funzione restituisce 1 se almeno uno degli elementi
// di A è divisore di tutti gli elementi di una qualsiasi riga di M.