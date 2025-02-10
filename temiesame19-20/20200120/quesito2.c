#include <stdio.h>

#define ROWS 4
#define COLS 4

int contaDominanti(int mat[ROWS][COLS], int rows, int cols) {
    int dominanti = 0;
    int i, j, di, dj;
    int dominante = 1;

    for(i = 0; i < ROWS - 1; i++) {
        for(j = 0; j < COLS - 1; j++) {
            dominante = 1;

            for(di = i + 1; di < ROWS; di++) {
                if(dominante == 0) break;

                for(dj = j + 1; dj < COLS; dj++) {
                    if(mat[i][j] < mat[di][dj]) dominante = 0;
                    if(dominante == 0) break;
                }
            }
            
            if(dominante) {
                dominanti += 1;
            }
        }
    }

    return dominanti;
}

int main() {
    int mat[ROWS][COLS] = {
        {11, 123213, 13, 40},
        {10,  2312,  3,  4},
        { 5, 201,  6,  7},
        { 8,  9, 30, 10}
    };

    int numDominanti = contaDominanti(mat, ROWS, COLS);

    printf("Numero di elementi dominanti: %d\n", numDominanti);

    return 0;
}