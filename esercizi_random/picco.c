#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define PICCO_CONFRONTO 8

int main() {
    int matrix[ROWS][COLS];
    int d1List[ROWS * COLS];
    int picco;
    int contatore = 0;
    int i, j, x, trovato = 0;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate random values for the matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100; // Random number between 0 and 99
        }
    }

    // Print the matrix
    printf("Random 10x10 Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d", matrix[i][j]); // Format for aligned output
        }
        printf("\n");
    }

    for (i = 0; i < (ROWS * COLS); i++) {
        d1List[i] = matrix[i / COLS][i % COLS];
    }

    for (i = 0; i < (ROWS * COLS); i++) {
        printf("%d ", d1List[i]);
    }

    printf("\n");

    for(x = PICCO_CONFRONTO; x < (ROWS * COLS) - PICCO_CONFRONTO; x++) {
        if(x == PICCO_CONFRONTO) picco = d1List[x];

        for (i = 1; i <= PICCO_CONFRONTO; i++) {
            printf("PICCO: %d CONFRONTO +: %d CONFRONTO -: %d\n", picco, d1List[x + i], d1List[x - i]);

            if(picco < d1List[x + i]) {
                picco = d1List[x + i];
                x += i;
                trovato = 0;
                break;
            }

            if(picco < d1List[x - i]) {
                for (j = i; j < PICCO_CONFRONTO; j++) {
                    if(picco < d1List[x + j]) {
                        picco = d1List[x + j];
                        x += j;
                        trovato = 0;
                        break;
                    }
                }
                if(j == PICCO_CONFRONTO) {
                    x += PICCO_CONFRONTO;
                }
                trovato = 0;
                break;
            }

            trovato = 1;          
        }

        if(trovato == 1) {
            printf("PICCO: %d\n", picco);
            printf("COLONNA: %d RIGA: %d\n", x % COLS, x / COLS);
            break;
        }
    }

    return 0;
}