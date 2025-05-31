#include <stdio.h>

#define ROWS 5
#define COLS 5

// Dichiarazione del sottoprogramma (implementazione da fornire altrove)
void filtroMediaMobile(int image[ROWS][COLS], double filtered[ROWS][COLS], int rows, int cols) {
    int i, j;
    int i3, j3;
    double mediaDivisore = 9;
    double media = 0;

    for(i = 0; i  < rows; i++) {
        for(j = 0; j < cols; j++) {
            media = 0;

            if(i > 0) {
                if(j > 0) {
                    media += image[i - 1][j - 1];
                }

                if(j < COLS - 1) {
                    media += image[i - 1][j + 1];
                }

                media += image[i - 1][j];
            }

            if(j > 0) {
                media += image[i][j - 1];
            }

            if(j < COLS - 1) {
                media += image[i][j + 1];
            }

            media += image[i][j];

            if(i < ROWS - 1) {
                if(j > 0) {
                    media += image[i + 1][j - 1];
                }
    
                if(j < COLS - 1) {
                    media += image[i + 1][j + 1];
                }

                media += image[i + 1][j];
            }

            media = media / mediaDivisore;
            filtered[i][j] = media;
        }
    }
}

int main(void) {
    int image[ROWS][COLS] = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    double filtered[ROWS][COLS];
    int i, j;

    // Applica il filtro a media mobile all'immagine di partenza
    filtroMediaMobile(image, filtered, ROWS, COLS);

    // Stampa dell'immagine filtrata
    printf("Immagine filtrata:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%lf ", filtered[i][j]);
        }
        printf("\n");
    }

    return 0;
}