#include <stdio.h>

// Dichiarazione del sottoprogramma
int contaUnoStratoMinZero(const int* valori, int righe, int colonne, int strati) {
    int zeroCount = 0;
    int unoCount = 0;

    int minZero = righe * colonne;
    int minUno = 0;

    int i, j, z;
    int indice = 0;

    for(z = 0; z < strati; z++) {
        zeroCount = 0;
        unoCount = 0;

        for(i = 0; i < righe; i++) {
            for(j = 0; j < colonne; j++) {
                if(valori[indice] == 0) {
                    zeroCount += 1;
                }
                if (valori[indice] == 1) {
                    unoCount += 1;
                }

                indice ++;
            }
        }

        if(zeroCount < minZero) {
            minZero = zeroCount;
            minUno = unoCount;
        }
    }

    return minUno;
}

int main() {
    int valori[] = {
        1, 2, 3, 4, 5, 6,  // Strato 1
        7, 8, 9, 0, 1, 2,  // Strato 2
        1, 1, 1, 1, 0, 0   // Strato 3
    };
    int righe = 2;
    int colonne = 3;
    int strati = 3;

    int risultato = contaUnoStratoMinZero(valori, righe, colonne, strati);
    
    printf("Il numero di 1 nello strato con meno 0 è: %d\n", risultato);

    return 0;
}
