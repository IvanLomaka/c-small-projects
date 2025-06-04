#include <stdio.h>

#define RIGHE 4
#define COLONNE 4

int contaDominanti(int matrice[RIGHE][COLONNE], int righe, int colonne) {
    int i, j, y, x;
    int dominanti = 0;
    int check = 1;
    int num;

    
    for (i = 0; i < righe - 1; i++) {

        for (j = 0; j < colonne - 1; j++) {
            check = 1;
            num = matrice[i][j];

            for (y = i + 1; y < righe; y++) {

                for (x = j + 1; x < colonne; x++) {
                    if(matrice[y][x] > num) check = 0;
                }

            }

            if(check == 1) dominanti ++;
        }

    }

    return dominanti;
}

int main(void) {
    int matrice[RIGHE][COLONNE] = {
        {10000,  5,  7,  3},
        { 4, 100,  6,  2},
        { 1,  8, 14,  9},
        { 0,  3,  5, 11}
    };

    int numeroDominanti = contaDominanti(matrice, RIGHE, COLONNE);
    printf("Numero di elementi dominanti: %d\n", numeroDominanti);

    return 0;
}
