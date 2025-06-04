#include <stdlib.h>
#include <stdio.h>

#define NC_MAPPA 10
#define NC_AREA 6

void cercaSottomatrice(int m[][NC_MAPPA], int sM[][NC_AREA], int nC, int nR, int sMnC, int sMnR, int *iM, int *jM) {
    int i, j, y, x;
    int check;
    int found = 0;
    
    *iM = -1;
    *jM = -1;

    check = 0;
    for(i = 0; i <= nR - sMnR && !found; i++) {
        for(j = 0; j <= nC - sMnC && !found; j++) {
            check = 1;

            for(y = 0; y < sMnR && check; y++) {
                for(x = 0; x < sMnC && check; x++) {
                    if(m[i + y][j + x] != sM[y][x]) check = 0;
                }
            }

            if(check) {
                *iM = i;
                *jM = j;
                found = 1;
            }
        }
    }
}

int main(void) {
    int mappa[10][NC_MAPPA] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {2, 3, 4, 5, 6, 7, 8, 9, 0, 1},
        {3, 4, 5, 6, 7, 8, 9, 0, 1, 2},
        {4, 5, 6, 7, 8, 9, 0, 1, 2, 3},
        {5, 6, 7, 8, 9, 0, 1, 2, 3, 4},
        {6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
        {7, 8, 9, 0, 1, 2, 3, 4, 5, 6},
        {8, 9, 0, 1, 2, 3, 4, 5, 6, 7},
        {9, 0, 1, 2, 3, 4, 5, 6, 7, 8}
    };

    int area[2][NC_AREA] = {
        {7, 8, 9, 0, 1, 2},
        {8, 9, 0, 1, 2, 3}
    };

    int iTrovato, jTrovato;

    cercaSottomatrice(mappa, area, 10, 10, 6, 2, &iTrovato, &jTrovato);

    if(iTrovato != -1 && jTrovato != -1) {
        printf("Sottomatrice trovata in posizione: (%d, %d)\n", iTrovato, jTrovato);
    } else {
        printf("Sottomatrice non trovata.\n");
    }

    return 0;
}
