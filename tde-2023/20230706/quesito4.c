#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NCOL 10

void stampaPicchi(int mat[][NCOL], int nR, int nC) {
    int i, j, y, x;
    int num;
    int sum;

    for(i = 0; i < nR; i++) {
        for(j = 0; j < nC; j++) {
            num = mat[i][j];
            sum = 0;
            
            for(y = -1; y <= 1; y++) {
                for(x = -1; x <= 1; x++) {
                    if(!(i + y == i && j + x == j)) {
                        if( i + y >= 0 && i + y < nR && j + x >= 0 && j + x < nC) {
                            sum += mat[i + y][j + x];
                        }
                    }
                }
            }

            if(num == sum) {
                printf("%d, %d\n", i, j);
            }
        }
    }
}

int main(void) {
    int mat[5][NCOL] = {
        {1, 2, 1, 4, 5},
        {0, 0, 0, 0, 0},
        {2, 9, 0, 3, 1},
        {1, 5, 1, 1, 8},
        {2, 2, 2, 2, 1}
    };

    int righe = 5;
    int colonne = 5;

    printf("Coordinate dei picchi (valore == somma vicini):\n");
    stampaPicchi(mat, righe, colonne);

    return 0;
}
