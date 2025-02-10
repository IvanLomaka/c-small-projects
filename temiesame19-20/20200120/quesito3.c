#include <stdio.h>
#include <stdlib.h>

int verificaIntervallo(int v[], int len, int da, int a) {
    int i = 0, j = 0;

    int *temporan = (int *)malloc(sizeof(int) * len);

    int temp = 0;
    int start = da;

    if(len != (a - da) + 1) return 0;

    for(i = 0; i < len; i++) {
        temporan[i] = v[i];
    }

    for (i = 0; i < len; i++) {
        for(j = 0; j < len - 1; j++) {
            if(temporan[j] > temporan[j + 1]) {
                temp = temporan[j];
                temporan[j] = temporan[j + 1];
                temporan[j + 1] = temp;
            }
        }
    }


    for(i = 0; i < len; i++) {
        if(temporan[i] != start) {
            free(temporan);
            return 0;
        }
        start ++;
    }

    free(temporan);

    return 1;
}

int main() {
    int v[] = {3, 4, 5, 6, 7};  // Array preimpostato
    int len = sizeof(v) / sizeof(v[0]);
    int da = 3, a = 7;  // Intervallo da verificare

    if (verificaIntervallo(v, len, da, a)) {
        printf("L'array contiene tutti e soli i valori nell'intervallo [%d, %d] senza ripetizioni.\n", da, a);
    } else {
        printf("L'array NON contiene tutti e soli i valori nell'intervallo [%d, %d] senza ripetizioni.\n", da, a);
    }

    return 0;
}
