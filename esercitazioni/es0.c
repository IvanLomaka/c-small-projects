#include <stdlib.h>
#include <stdio.h>

int main() {
    int *arr;
    int n = 5;

    // Allocazione dinamica di un array di 5 interi
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memoria non disponibile!\n");
        return 1;
    }

    // Inizializzazione e utilizzo
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Stampa dell'array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Rilascio della memoria
    free(arr);

    printf("%d ", arr[1]);

    return 0;
}
