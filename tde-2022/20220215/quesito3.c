#include <stdio.h>

#define RMAX 10
#define CMAX 8

int contaSottomatrici(int mappa[RMAX][CMAX], int dimh, int dimv, int righe, int colonne) {
    int i, j, y, x;
    int count = 0;
    int check;

    for(i = 0; i <= righe - dimv; i++) {
        for(j = 0; j <= colonne - dimh; j++) {
            check = 1;

            for(y = 0; y < dimv && check; y++) {

                for(x = 0; x < dimh && check; x++) {
                    if(mappa[i + y][j + x] <= 0) check = 0;
                }

            }

            if(check) count += 1;
        }
    }

    return count;
}

int main(void) {
    int mappa[RMAX][CMAX] = {
        {  1, -4,  7,  3,  8, -4,  5,  0},
        { -2,  3,  3,  7,  1, -5, -9,  0},
        {  1,  3,  1,  2,  2, -4, -9,  0},
        { -2,  3,  3,  3,  2, -1, -8,  0},
        {  2,  0,  3,  1,  2,  1,  8,  0},
        {  1,  1,  6,  1,  1,  9,  6,  0},
        {  1, -1,  3,  2,  4,  0,  6,  0},
        {  3,  7,  3,  1,  1,  1,  2,  0},
        { -1,  3,  0,  5,  3,  9,  6,  0},
        {  1,  1,  1,  7,  1,  6,  6,  0}
    };

    int dimh = 4;
    int dimv = 3;
    int risultato;


    risultato = contaSottomatrici(mappa, dimh, dimv, RMAX, CMAX);
    printf("Numero di sottomatrici %dx%d con tutti valori > 0: %d\n", dimh, dimv, risultato);

    return 0;
}
