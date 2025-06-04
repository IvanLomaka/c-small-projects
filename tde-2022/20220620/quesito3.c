#include <stdio.h>

#define RMAX 5
#define CMAX 5

int contapicchi(int mat[][CMAX], int righe, int colonne) {
    int i, j;
    int y;
    int num;
    int check;
    int count = 0;

    for(i = 0; i < righe; i++) {
        for(j = 0; j < colonne; j++) {
            num = mat[i][j];
            check = 1;

            for(y = 0; y < righe && check; y++) {    
                if(num <= mat[y][j] && !(i == y)) check = 0;
            }

            for(y = 0; y < colonne && check; y++) {    
                if(num <= mat[i][y] && !(j == y)) check = 0;
            }

            if(check) count++;
        }
    }

    return count;
}

int main(void) {
    int mappa[RMAX][CMAX] = {
        {  3,  4,  1,  8,  6 },
        {  9,  7,  8,  4,  3 },
        {  5, 12, 10, 11,  2 },
        {  6,  4,  7, 13,  1 },
        {  0,  5,  2,  3, 14 }
    };

    int righe = 5;
    int colonne = 5;

    int num_picchi = contapicchi(mappa, righe, colonne);

    printf("Numero di picchi trovati: %d\n", num_picchi);

    return 0;
}
