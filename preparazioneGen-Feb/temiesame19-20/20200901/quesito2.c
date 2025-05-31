#include <stdio.h>
#include <stdlib.h>

int isPrime(int n) {
    int i = 0;

    if(n == 0 || n == 1) return 0;
    if(n % 2 == 0) return 0;

    for(i = 3; i < (n + 2) / 2; i += 2) {
        if(n % i == 0) return 0; 
    }

    return 1;
}

int compattaArray(int array[], int lenArray) {
    int dimensioni = 0;
    int *arrayRidotto = (int *)malloc(sizeof(int) * lenArray);
    if(arrayRidotto == NULL) return -1;
    int i = 0;
    
    for (i = 0; i < lenArray; i++) {
        if(isPrime(array[i])) {
            arrayRidotto[dimensioni] = array[i];
            dimensioni += 1;
        }
    }

    array = (int *)realloc(array, sizeof(int) * dimensioni);
    if(array == NULL) return -1;

    for (i = 0; i < dimensioni; i++) {
        array[i] = arrayRidotto[i];
    }

    free(arrayRidotto);

    return dimensioni;
}

int main() {
    int *array;
    int dimEnd;
    int n;
    int i;

    // Richiedere all'utente un numero valido tra 1 e 200
    do {
        printf("Quanti numeri vuoi inserire? (1-200): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 200);

    // Allocazione dinamica dell'array
    array = (int *)malloc(sizeof(int) * n);
    if (array == NULL) {
        printf("Errore di allocazione della memoria.\n");
        return 1;
    }

    // Acquisizione dei dati con input valido (numeri positivi)
    printf("Inserisci %d numeri positivi:\n", n);
    for (int i = 0; i < n; i++) {
        do {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &array[i]);
            if (array[i] < 0) {
                printf("Errore: inserisci un numero positivo.\n");
            }
        } while (array[i] < 0);
    }

    dimEnd = compattaArray(array, n);

    for (i = 0; i < dimEnd; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    free(array);

    return 0;
}