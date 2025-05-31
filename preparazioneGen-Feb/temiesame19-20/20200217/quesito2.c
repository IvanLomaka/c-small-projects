#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Dichiarazione del sottoprogramma (implementazione da fornire altrove)
int *conta(const char *info, const char *cars) {
    int *risultati = (int *)malloc(sizeof(int) * strlen(cars));
    int i = 0;
    int j = 0;
    int count = 0;

    for (i = 0; i < strlen(cars); i++) {
        count = 0;

        for (j = 0; j < strlen(info); j++) {
            if(cars[i] == info[j]) {
                count ++;
            }
        }

        printf("%d ", count);

        risultati[i] = count;
    }

    return risultati;
}

int main(int argc, char *argv[]) {
    int *risultati;

    if(argc != 3) {
        return 1;
    }

    // Chiamata alla funzione conta
    risultati = conta(argv[argc - 2], argv[argc - 1]);

    // Stampa dei risultati
    printf("Conteggio dei caratteri:\n");
    for (int i = 0; i < strlen(argv[argc - 1]); i++) {
        printf("%c: %d\n", argv[argc - 1][i], risultati[i]);
    }

    return 0;
}
