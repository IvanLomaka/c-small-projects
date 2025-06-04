#include <stdlib.h>
#include <stdio.h>

#define NC 8

int maxLen(int matrice[][NC], int nC, int nR, int *mi, int *mj) {
    int i, j, z;
    int count = 0;
    int maxCount = 0;

    for(i = 0; i < nR; i++) {
        for(j = 0; j < nC; j++) {
            if(matrice[i][j] == 1) {
                count = 1;
                for(z = j + 1; z < nC; z++) {
                    if(matrice[i][z] == 1) count++;
                    else break;
                }

                if(count > maxCount) {
                    maxCount = count;
                    *mi = i;
                    *mj = j;
                }

                j = (z - 1);
            }
        }
    }

    return maxCount;
}

int main(void) {
    int matrice[7][NC] = {
        {1, 0, 1, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 1, 1, 1},
        {1, 0, 1, 1, 0, 1, 1, 0}
    };

    int riga, colonna;
    int lunghezza = maxLen(matrice, NC, 8, &riga, &colonna);

    printf("Segmento massimo: inizio (%d,%d), lunghezza %d\n", riga, colonna, lunghezza);
    return 0;
}
