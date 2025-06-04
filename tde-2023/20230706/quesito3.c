#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int elementiContigui(int arr[], int arrLen, int k) {
    int i;
    int j;
    int somma;
    int sommaMax;
    
    if(k > arrLen) {
        somma = 0;
        for(i = 0; i < arrLen; i++) {
            somma += arr[i];
        }

        return somma;
    }

    for(i = 0; i <= arrLen - k; i++) {
        somma = 0;
        for(j = 0; j < k; j++) {
            somma += arr[i + j];
        }

        if(i == 0) sommaMax = somma;
        if(somma > sommaMax) sommaMax = somma;
    }

    return sommaMax;
}

int main(void) {
    int v[] = {1, 2, -4, 1, 3, -5, 2, 10, -1, 0};
    int k = 7;
    int len = sizeof(v) / sizeof(v[0]);

    int risultato = elementiContigui(v, len, k);
    printf("Risultato: %d\n", risultato);

    return 0;
}
