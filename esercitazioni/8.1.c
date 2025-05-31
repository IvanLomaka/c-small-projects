// 8.1 Scrivere un programma che chiede all’utente di inserire i dati interi di
// una matrice bidimensionale quadrata di dimensione 3. Il programma calcola la
// matrice ruotata di 90 gradi in senso antiorario, salvandola in una nuova variabile
// e visualizza il risultato.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrice[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matriceRuotata[3][3];
    int i, j;
    int colonna = 2;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            matriceRuotata[i][j] = matrice[j][colonna];
        }
        colonna --;
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", matriceRuotata[i][j]);
        }

        printf("\n");
    }

    return 0;
}