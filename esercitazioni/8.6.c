#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5

typedef struct {
    int rows;    // Numero effettivo di righe
    int cols;    // Numero effettivo di colonne
    float data[MAX_SIZE][MAX_SIZE]; // Dati della matrice
} Matrix;

// Funzione per popolare una matrice con valori casuali
void populateMatrix(Matrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            mat->data[i][j] = (float)(rand() % 100) / 10.0; // Valori casuali tra 0.0 e 9.9
        }
    }
}

// Funzione per stampare una matrice
void printMatrix(const Matrix* mat) {
    printf("Matrix %dx%d:\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%6.2f ", mat->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows;
    int cols;
    Matrix matrice1;
    Matrix matrice2;

    int i, j, z;
    float productCell = 0;

    int goodInput = 0;

    srand(time(NULL)); // Inizializza il generatore di numeri casuali

    // Input delle dimensioni delle matrici
    while (!goodInput) {
        printf("Enter rows and columns (max %d):\n", MAX_SIZE);
        if (scanf("%d %d", &rows, &cols) == 2) {
            if (rows > 0 && rows <= MAX_SIZE && cols > 0 && cols <= MAX_SIZE) {
                goodInput = 1;
            } else {
                printf("Invalid input. Please enter values between 1 and %d.\n", MAX_SIZE);
            }
        } else {
            printf("Invalid input. Please enter two integers.\n");
            while (getchar() != '\n'); // Pulisce il buffer di input
        }
    }

    // Inizializza le dimensioni delle matrici
    matrice1.rows = rows;
    matrice1.cols = cols;
    matrice2.rows = rows;
    matrice2.cols = cols;

    // Popola le matrici con valori casuali
    populateMatrix(&matrice1);
    populateMatrix(&matrice2);

    // Stampa le matrici
    printf("\nMatrix 1:\n");
    printMatrix(&matrice1);

    printf("\nMatrix 2:\n");
    printMatrix(&matrice2);
    printf("\n");

    if(rows == cols) {
        for(i = 0; i < rows; i++) {
            for(j = 0; j < cols; j++) {
                productCell = 0.0;

                for (z = 0; z < rows; z++) {
                    productCell += (matrice1.data[i][z] * matrice2.data[z][j]);
                }

                printf("%6.2f ", productCell);
            }

            printf("\n");
        }
    }

    return 0;
}
