#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

void lunghezzaMax(int arr[], int *lunghezzaMax, int *indiceMax) {
    int lunghezza = 1;
    int indice = 0;
    int i;

    if (LEN < 1) {
        *lunghezzaMax = 1;
        *indiceMax = 0;
        return;
    }

    for(i = 0; i < LEN - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            lunghezza++;
        } else {
            if (lunghezza >= *lunghezzaMax) {
                *lunghezzaMax = lunghezza;
                *indiceMax = indice;
            }
            lunghezza = 1;
            indice = i + 1;
        }
    }

    return;
}

int main() {
    int arr[LEN];
    int maxLunghezza = 0;
    int indiceMax = 0;
    srand(time(0));

    for (int i = 0; i < LEN; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }

    printf("Random array: ");
    for (int i = 0; i < LEN; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    lunghezzaMax(arr, &maxLunghezza, &indiceMax);

    printf("Lunghezza massima: %d\n", maxLunghezza);
    printf("Indice massimo: %d\n", indiceMax);

    return 0;
}