#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define COLONNE 7
#define RIGHE 6

int checkMatrice(int matrix[][COLONNE], int array[], int len, int nR, int nC) {
    int i, j, z;
    int counter = 0;
    int check;

    for(i = 0; i < nR; i++) {
        for(j = 0; j <= nC - len; j++) {
            check = 1;
            for(z = 0; z < len && check; z++) {
                if(matrix[i][j + z] != array[z]) check = 0;
            }
            if(check) counter++;
        }
    }

    return counter;
}

int main(void) {
    int A[RIGHE][COLONNE] = {
        {10, 4, 7, 3, 8, 4, 5},
        {2, 1, 3, 8, 5, 5, 9},
        {1, 17, 6, 5, 4, 11, 6},
        {3, 7, 3, 8, 3, 8, 5},
        {1, 3, 8, 2, 4, 12, 16},
        {0, 0, 0, 0, 0, 0, 0}
    };
    int b[] = {3, 8, 5};
    int risultato;

    risultato = checkMatrice(A, b, 3, RIGHE, COLONNE);
    printf("Numero di righe in cui b compare: %d\n", risultato);

    return 0;
}
