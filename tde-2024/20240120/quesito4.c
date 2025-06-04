#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int valori(int valori[], int righe, int colonne, int strati) {
    int currentUno;
    int currentZero;

    int minZero = righe * colonne;
    int minUno = 0;

    int i, j;

    for(i = 0; i < strati; i++) {
        currentUno = 0;
        currentZero = 0;

        for(j = 0; j < righe * colonne; j++) {
            if(valori[j + i * righe * colonne] == 0) currentZero ++;
            if(valori[j + i * righe * colonne] == 1) currentUno ++;
        }

        if(currentZero < minZero) {
            minUno = currentUno;
            minZero = currentZero;
        }
    }

    return minUno;
}

int main(void) {
    int righe = 4;
    int colonne = 6;
    int strati = 5;
    int valore[] = {
        2,2,0,2,2,2,
        2,1,0,2,0,2,
        2,2,2,0,2,2,
        2,2,2,2,2,2,
        2,2,0,1,2,2,
        2,2,2,2,2,2,
        1,0,2,2,2,2,
        0,2,1,0,2,0,
        2,2,0,2,2,2,
        2,2,1,2,2,2,
        1,2,2,2,2,2,
        2,1,2,2,1,2,
        1,2,2,0,2,2,
        2,2,2,2,2,2,
        0,2,2,2,1,2,
        1,2,2,2,2,2,
        1,2,0,2,0,2,
        2,2,2,0,2,2,
        2,2,2,2,0,2,
        2,2,2,2,2,2
    };

    int risultato = valori(valore, righe, colonne, strati);
    printf("Numero di 1 nello strato con meno 0: %d\n", risultato);

    return 0;
}
