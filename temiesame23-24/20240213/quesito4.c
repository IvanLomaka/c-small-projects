#include <stdio.h>

#define NC_MAPPA 5
#define NC_AREA 3

void trovaArray(int mappa[][NC_MAPPA], int area[][NC_AREA], int *row, int *col) {
    if(NC_AREA > NC_MAPPA) {
        printf("Errore: la dimensione dell'area è maggiore della mappa.\n");
        *row = -1;
        *col = -1;
        return;
    }
    
    int check = 1;
    int iMappa, jMappa;

    int iArea, jArea;


    for (iMappa = 0; iMappa <= NC_MAPPA - NC_AREA; iMappa++) {
        for (jMappa = 0; jMappa <= NC_MAPPA - NC_AREA; jMappa++) {
            check = 1;

            for(iArea = 0; iArea < NC_AREA && check; iArea++) {
                for(jArea = 0; jArea < NC_AREA && check; jArea++) {
                    if(mappa[iMappa + iArea][jMappa + jArea] != area[iArea][jArea]) {
                        check = 0;
                    }
                }
            }

            if(check) {
                *row = iMappa;
                *col = jMappa;
                return;
            }
        }
    }

    *row = -1;
    *col = -1;
}

int main() {
    int mappa[NC_MAPPA][NC_MAPPA] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int area[NC_AREA][NC_AREA] = {
        {8, 9, 10},
        {13, 14, 15},
        {18, 19, 20}
    };

    int row = -1, col = -1;

    // Chiamata al sottoprogramma (da implementare)
    trovaArray(mappa, area, &row, &col);

    if (row != -1 && col != -1) {
        printf("L'array è stato trovato alla posizione: riga %d, colonna %d\n", row, col);
    } else {
        printf("L'array non è stato trovato.\n");
    }

    return 0;
}