#include <stdlib.h>
#include <stdio.h>

#define RMAX 5
#define CMAX 7

int contaPozzi(int mat[][CMAX], int nR, int nC) {
    int i, j, z;
    int conta = 0;
    int check;
    int num;

    for(i = 0; i < nR; i++) {
        for(j = 0; j < nC; j++) {
            num = mat[i][j];
            check = 1;

            for(z = 0; z < nR && check; z++) {
                if(num >= mat[z][j] && z != i) check = 0;
            }

            for(z = 0; z < nC && check; z++) {
                if(num >= mat[i][z] && z != j) check = 0;
            }

            if(check) conta ++;
        }
    }

    return conta;
}

int main(void) {
    int mappa[RMAX][CMAX] = {
        {1, 1, 6, 1, 1, 9, 6},
        {1, -5, 3, 2, 4, 0, 6},
        {3, 7, 3, 1, 1, 1, 2},
        {-1, 3, 0, 5, 3, 9, 6},
        {1, 1, 1, 7, 1, 6, 6}
    };
    
    int righe = 5;
    int colonne = 7;

    int numeroPozzi = contaPozzi(mappa, righe, colonne);
    printf("Numero di pozzi nella mappa: %d\n", numeroPozzi);

    return 0;
}
