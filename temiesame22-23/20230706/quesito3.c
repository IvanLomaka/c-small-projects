#include <stdio.h>

int calcolaMaxSommaContigua(int integers[], int arraySize, int k) {
    int sum = 0;
    int maxSum = 0;
    int i, j;
    
    if(arraySize < k) {
        for(i = 0; i < arraySize; i++) {
            sum = sum + integers[i];
        }

        return sum;
    }

    for(i = 0; i <= arraySize - k; i++) {
        sum = 0;
        for (j = 0; j < k; j++) {
            sum = sum + integers[i + j];
        }

        if(sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}

int main() {
    int v[] = {1, 2, -4, 1, 3, -5, 2, 10, -1, 0};  // Esempio di array
    int k = 7;  // Esempio di k positivo
    int n = sizeof(v) / sizeof(v[0]);  // Calcolare la lunghezza dell'array
    int max_sum = 0;  // Variabile per memorizzare il massimo della somma di k elementi

    // Chiamata alla funzione che calcola il massimo della somma di k elementi contigui
    max_sum = calcolaMaxSommaContigua(v, n, k); // Supponiamo che questa funzione esista
    
    printf("Il massimo della somma di %d elementi contigui è: %d\n", k, max_sum);
    
    return 0;
}
