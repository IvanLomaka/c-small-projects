#include <stdio.h>
#include <stdlib.h>

#define NR 8
#define NC 10

void erutta(int matrix[][NC], int erutI, int erutJ, int nR, int nC) {
    int i, j;
    int num;

    if((erutI >= 0 && erutI < nR) && (erutJ >= 0 && erutJ < nC)) {
        num = matrix[erutI][erutJ];

        for (i = -1; i <= 1; i++) {
            for (j = -1; j <= 1; j++) {
                if( erutI + i >= 0 && erutI + i < nR &&
                    erutJ + j >= 0 && erutJ + j < nC) {
                    
                    if(matrix[erutI + i][erutJ + j] < num) {
                        matrix[erutI + i][erutJ + j] += 1;
                    }
                }
            }
        }

        matrix[erutI][erutJ] += 2;
    }
}

void visualizzamappa(int matrix[][NC], int nR, int nC) {
    int i, j;

    for(i = 0; i < nR; i++) {
        for(j = 0; j < nC; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int main(void) {
    int mappa[NR][NC] = {
        {3,0,6,1,5,1,5,6,8,1},
        {0,0,5,6,0,5,4,0,5,6},
        {1,0,8,1,2,6,4,6,5,6},
        {5,1,8,6,0,0,0,0,0,0},
        {3,1,3,0,4,1,2,1,5,6},
        {5,1,5,1,3,1,1,0,7,1},
        {5,1,5,1,0,0,5,6,2,3},
        {3,1,8,1,0,0,0,0,0,0}
    };

    int x = 3;
    int y = 2;

    printf("Mappa PRIMA dell'eruzione in (%d, %d):\n", x, y);
    visualizzamappa(mappa, NR, NC);

    erutta(mappa, x, y, NR, NC);

    printf("\nMappa DOPO l'eruzione in (%d, %d):\n", x, y);
    visualizzamappa(mappa, NR, NC);

    return 0;
}
