#include <stdlib.h>
#include <stdio.h>

#define NR 6
#define NC 5

void trovaPicchi(int mat[][NC], int nR, int nC, int *piccoI, int *piccoJ) {
    int i, j, y, x;
    int picco;
    int piccoTrovato = 0;
    int check;

    *piccoI = -1;
    *piccoJ = -1;

    for(i = 1; i < nR - 1 && !piccoTrovato; i++) {
        for(j = 1; j < nC - 1 && !piccoTrovato; j++) {
            check = 1;
            picco = mat[i][j];

            for(y = -1; y <= 1 && check; y++) {
                for(x = -1; x <= 1 && check; x++) {
                    if(i + y != i && j + x != j) {
                        if(picco <= mat[i + y][j + x]) check = 0;
                    }
                }
            }

            if(check) {
                piccoTrovato = 1;
                *piccoI = i;
                *piccoJ = j;
            }
        }
    }
}

int main(void) {
    int matrice[NR][NC] = {
        {1, 2, 1, 4, 5},
        {2, 5, 1, 1, 6},
        {2, 1, 2, 5, 4},
        {1, 3, 3, 1, 3},
        {4, 1, 1, 4, 1},
        {1, 5, 3, 2, 2}
    };

    int piccoI, piccoJ;
    trovaPicchi(matrice, NR, NC, &piccoI, &piccoJ);

    if (piccoI == -1 && piccoJ == -1) {
        printf("Nessun picco trovato.\n");
    } else {
        printf("Picco trovato in posizione (%d, %d) con valore %d.\n", piccoI, piccoJ, matrice[piccoI][piccoJ]);
    }

    return 0;
}
