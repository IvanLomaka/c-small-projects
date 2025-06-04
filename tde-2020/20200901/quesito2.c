#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

int isPrime(int n) {
    int i;

    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    
    for(i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return 0;
    }

    return 1;
}

int compattaarray(int arr[], int len) {
    int eliminated = 0;
    int i;

    for(i = 0; i < len; i++) {
        if(isPrime(arr[i])) {
            arr[i - eliminated] = arr[i];
        } else {
            eliminated++;
        }
    }

    return len - eliminated;
}

int main(void) {
    int arr[MAX_SIZE] = { 0 };
    int size = 201;
    int i = 0;
    int removed;

    while (scanf("%d", &size) != 1 || size > 200 || size < 1) {
        printf("Riprova!\n");
        while (getchar() != '\n');
    }

    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    removed = compattaarray(arr, size);

    for(i = 0; i < removed; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n%d\n", removed);

    return 0;
}
