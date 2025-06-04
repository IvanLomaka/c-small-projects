#include <stdio.h>

#define RIGHE 3
#define COLONNE 4

void centra(int m[RIGHE][COLONNE], double c[RIGHE][COLONNE], int nR, int nC) {
    int sum;
    int i,j,z;
    int num;

    for (i = 0; i < nR; i++) {
        for (j = 0; j < nC; j++) {
            num = m[i][j];
            sum = 0;

            for (z = 0; z < nR; z++) {
                sum += m[z][j];
            }

            c[i][j] = num - (sum / nR);
        }
    }
}

int main(void) {
    int m[RIGHE][COLONNE] = {
        {4,  8,  6, 10},
        {2, 12,  5,  8},
        {6, 10,  7,  9}
    };

    int i, j;

    double c[RIGHE][COLONNE];

    centra(m, c, RIGHE, COLONNE);

    for (i = 0; i < RIGHE; i++) {
        for (j = 0; j < COLONNE; j++) {
            printf("%.2f ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
