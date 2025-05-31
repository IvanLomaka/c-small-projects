#include <stdio.h>
#define NCOL 5  // Numero di colonne specificato

// Funzione per controllare se un elemento è un picco
int isPicco(int arr[][NCOL], int row, int col) {
    int value = arr[row][col];

    // Confronta l'elemento con tutti gli 8 vicini
    return value > arr[row-1][col-1] &&
           value > arr[row-1][col] &&
           value > arr[row-1][col+1] &&
           value > arr[row][col-1] &&
           value > arr[row][col+1] &&
           value > arr[row+1][col-1] &&
           value > arr[row+1][col] &&
           value > arr[row+1][col+1];
}

// Sottoprogramma per trovare il picco massimo
void trovaPiccoMassimo(int arr[][NCOL], int nrow, int *piccoRow, int *piccoCol) {
    int maxPicco = -1;
    *piccoRow = -1;
    *piccoCol = -1;

    for (int i = 1; i < nrow - 1; i++) {
        for (int j = 1; j < NCOL - 1; j++) {
            if (isPicco(arr, i, j)) {
                int current = arr[i][j];
                if (current > maxPicco) {
                    maxPicco = current;
                    *piccoRow = i;
                    *piccoCol = j;
                }
            }
        }
    }
}

int main() {
    int arr[4][NCOL] = {
        {10, 20, 15, 12, 11},
        {5, 25, 30, 10, 18},
        {14, 22, 20, 25, 17},
        {9, 11, 13, 14, 15}
    };

    int piccoRow, piccoCol;
    trovaPiccoMassimo(arr, 4, &piccoRow, &piccoCol);

    if (piccoRow == -1 && piccoCol == -1) {
        printf("Nessun picco trovato.\n");
    } else {
        printf("Picco massimo trovato a (%d, %d) con valore %d.\n", piccoRow, piccoCol, arr[piccoRow][piccoCol]);
    }

    return 0;
}