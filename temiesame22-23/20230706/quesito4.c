#include <stdio.h>

#define DIMC 5  // Definisci la dimensione delle colonne (5 nel tuo caso)

void trovaVicineUgualiSomma(int arr[][DIMC], int rows, int cols) {
    int i,j;
    int sum;
    
    for(i = 0; i < rows; i ++) {
        for (j = 0; j < cols; j++) {
            sum = 0;
            
            if (i - 1 >= 0) {
                if (j - 1 >= 0) {
                    sum += arr[i-1][j-1];
                }

                if (j + 1 < cols) {
                    sum += arr[i-1][j+1];
                }

                sum += arr[i-1][j];
            }

            if (i + 1 < rows) {
                if (j - 1 >= 0) {
                    sum += arr[i+1][j-1];
                }

                if (j + 1 < cols) {
                    sum += arr[i+1][j+1];
                }

                sum += arr[i+1][j];
            }

            if (j - 1 >= 0) {
                sum += arr[i][j-1];
            }

            if(j + 1 < cols) {
                sum += arr[i][j+1];
            }

            // printf("Row: %d, Col: %d\n", i, j);
            // printf("Sum: %d, Num: %d\n", sum, arr[i][j]);

            if (sum == arr[i][j]) {
                printf("Row: %d, Col: %d\n", i, j);
            }
        }
    }
}

int main() {
    // Dichiariamo l'array bidimensionale con i valori che hai fornito
    int arr[5][DIMC] = {
        {1, 2, 1, 4, 5},
        {0, 0, 0, 0, 0},
        {2, 9, 0, 3, 1},
        {1, 5, 1, 1, 8},
        {2, 2, 2, 2, 1}
    };

    // Chiamata al sottoprogramma che visualizza le coordinate
    // delle posizioni per cui il valore è uguale alla somma dei vicini
    trovaVicineUgualiSomma(arr, 5, DIMC);

    return 0;
}
