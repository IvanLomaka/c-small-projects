#include <stdio.h>

#define RIGHE 5
#define COLONNE 5

void filtroMediaMobile(float image[RIGHE][COLONNE], float filtered[RIGHE][COLONNE], int righe, int colonne) {
    int i, j, y, x;
    float sum;

    for(i = 0; i < righe; i++){
        for(j = 0; j < colonne; j++) {
            sum = 0;

            for(y = -1; y < 2; y++) {
                for(x = -1; x < 2; x++) {
                    if(i + y >= 0 && i + y < righe && j + x >= 0 && j + x < colonne) {
                        sum += image[i + y][j + x];
                    }
                }
            }

            filtered[i][j] = sum / 9;
        }
    }
}

int main(void) {
    int i, j;
    float image[RIGHE][COLONNE] = {
        {10, 20, 30, 40, 50},
        {15, 25, 35, 45, 55},
        {20, 30, 40, 50, 60},
        {25, 35, 45, 55, 65},
        {30, 40, 50, 60, 70}
    };

    float filtered[RIGHE][COLONNE] = {0};

    filtroMediaMobile(image, filtered, RIGHE, COLONNE);

    printf("Immagine filtrata:\n");
    for (i = 0; i < RIGHE; i++) {
        for (j = 0; j < COLONNE; j++) {
            printf("%6.2f ", filtered[i][j]);
        }
        printf("\n");
    }

    return 0;
}
