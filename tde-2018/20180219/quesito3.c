#include <stdio.h>

#define MAX_VALUE 25

int main(void) {
    int numbers[MAX_VALUE];
    int i; 
    int j;
    int z;
    
    int maxProdotto;
    int currentProdotto;

    for (i = 0; i < MAX_VALUE; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Errore: input non valido.\n");
            return 1;
        }
    }

    maxProdotto = numbers[1] * numbers[2] * numbers[3];

    for (i = 0; i < MAX_VALUE - 2; i++) {
        for (j = i + 1; j < (MAX_VALUE - 1); j++) {
            for (z = j + 1; z < MAX_VALUE; z++) {
                currentProdotto = numbers[i] * numbers[j] * numbers[z];
                if(currentProdotto > maxProdotto) maxProdotto = currentProdotto;
            }
        }
    }

    printf("%d\n", maxProdotto);

    return 0;
}